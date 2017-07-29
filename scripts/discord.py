# Copyright (c) Mathias Kaerlev 2013-2017.
#
# This file is part of cuwo.
#
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.

"""
Discord client that can be used as a way to control the game server

Depends on the discord package. Install with:
pip install -U discord.py
"""

import discord
from cuwo.common import parse_command
from cuwo.script import ServerScript, ConnectionScript, ScriptInterface


MAX_DISCORD_CHAT_SIZE = 100


class DiscordClient(discord.Client):
    commands = {}
    channel = None

    def __init__(self, script):
        super().__init__()
        self.script = script
        self.loop = script.loop
        self.server = self.script.server
        config = self.script.config
        self.interface = ScriptInterface('Discord', self.server,
                                         *config.rights)

    async def on_ready(self):
        print(f'Logged in to Discord as {self.user.name} {self.user.id}')
        for server in self.servers:
            await self.on_server_join(server)

    async def on_server_join(self, server):
        config = self.script.config
        channel = server.get_channel(config.channel_id)
        print(channel, server.id)
        if channel is None:
            return
        self.channel = channel
        print('Logged on to specified Discord channel')

    def has_role(self, user, roles):
        if roles is None:
            return True
        roles = set(roles)
        user_roles = set(role.name for role in user.roles)
        return not roles.isdisjoint(user_roles)

    async def on_message(self, message):
        if message.channel != self.channel:
            return
        user = message.author
        name = user.name
        data = message.content
        config = self.script.config
        command_prefix = config.command_prefix
        chat_prefix = config.chat_prefix
        if data.startswith(command_prefix):
            if not self.has_role(user, config.command_roles):
                return
            cmd = data[len(command_prefix):]
            result = self.handle_command(name, cmd)
            if not result:
                return
            self.send(f'{user.mention}: {result}')
        elif data.startswith(chat_prefix):
            top_role = user.top_role
            if not self.has_role(user, config.chat_roles):
                return
            data = data[len(chat_prefix):].strip()
            message = '<%s> %s' % (name, data)
            message = message[:MAX_DISCORD_CHAT_SIZE]
            print(message)
            self.server.send_chat(message)

    def handle_command(self, name, command):
        command, args = parse_command(command)
        try:
            return self.commands[command](self, *args)
        except KeyError:
            pass
        ret = self.server.call_command(self.interface, command, args)
        if ret is not None:
            return ret
        return 'Invalid command'

    def send(self, msg):
        if self.channel is None:
            return
        self.loop.create_task(self.send_message(self.channel, msg))


class DiscordScriptConnection(ConnectionScript):
    def on_join(self, event):
        self.parent.send(f'{self.connection.name} entered the game')

    def on_unload(self):
        if not self.connection.has_joined:
            return
        self.parent.send(f'{self.connection.name} disconnected')

    def on_chat(self, event):
        self.parent.send(f'<{self.connection.name}> {event.message}')


class DiscordScriptServer(ServerScript):
    connection_class = DiscordScriptConnection

    def on_load(self):
        config = self.server.config
        self.config = config.discord

        self.command_roles = self.config.command_roles
        self.chat_roles = self.config.chat_roles

        self.client = DiscordClient(self)
        self.loop.create_task(self.client.start(self.config.token))

    def on_unload(self):
        self.loop.create_task(self.client.logout())

    def send(self, *arg, **kw):
        if self.client is None:
            return
        self.client.send(*arg, **kw)


def get_class():
    return DiscordScriptServer


def discord(func):
    ServerPlugin.commands[func.__name__] = func
    return func


# @irc
# def who(bot):
#     """
#     Reimplemented here for the purpose of coloring the chat
#     """
#     server = bot.server
#     player_count = len(server.players)
#     if player_count == 0:
#         bot.me('has no players connected')
#         return
#     formatted_names = []
#     for player in list(server.players.values()):
#         name = '\x0302%s #%s' % (player.name, player.entity_id)
#         formatted_names.append(name)
#     noun = 'player' if player_count == 1 else 'players'
#     msg = 'has %s %s connected: ' % (player_count, noun)
#     msg += '\x0F, '.join(formatted_names)
#     bot.me(msg)