# Copyright (c) Mathias Kaerlev 2013-2014.
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
IRC client that can be used as a way to control the game server

Depends on the irc3 package. Install with:
pip install irc3
"""

import irc3
from cuwo.common import parse_command
from cuwo.script import ServerScript, ConnectionScript, ScriptInterface


MAX_IRC_CHAT_SIZE = 100


@irc3.plugin
class ServerPlugin:
    commands = {}

    def __init__(self, bot):
        self.bot = bot
        self.script = bot.config['script']
        self.server = self.script.server
        config = self.script.config
        self.chat_prefix = config.chatprefix
        self.command_prefix = config.commandprefix
        self.interface = ScriptInterface('IRC', self.server, *config.rights)
        self.command_users = set()
        self.chat_users = set()
        self.mode_dict = {}

        for symbol in self.script.chat_modes:
            self.mode_dict[symbol] = self.chat_users
        for symbol in self.script.command_modes:
            self.mode_dict[symbol] = self.command_users

    def connection_lost(self):
        self.command_users.clear()
        self.chat_users.clear()
        self.script.plugin = None

    @irc3.event(irc3.rfc.PRIVMSG)
    def on_privmsg(self, mask, event, target, data=None):
        if event != 'PRIVMSG':
            return
        user = mask.nick
        if user in self.command_users:
            prefix = '@'
        elif user in self.chat_users:
            prefix = '+'
        else:
            return
        prefix = '@' if user in self.command_users else '+'
        name = prefix + user
        if data.startswith(self.command_prefix):
            if user not in self.command_users:
                return
            cmd = data[len(self.command_prefix):]
            result = self.handle_command(name, cmd)
            if result is None:
                return
            self.send('%s: %s' % (user, result))
        elif data.startswith(self.chat_prefix):
            data = data[len(self.chat_prefix):].strip()
            message = '<%s> %s' % (name, data)
            message = message[:MAX_IRC_CHAT_SIZE]
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

    @irc3.event(irc3.rfc.JOIN_PART_QUIT)
    def on_join_part_quit(self, mask, event, channel=None, **kw):
        getattr(self, event.lower())(mask.nick, mask, channel)

    @irc3.event(irc3.rfc.KICK)
    def on_kick(self, mask, event, channel=None, target=None, **kw):
        self.part(target.nick, None, channel)

    def join(self, nick, mask, channel):
        if nick == self.bot.nick:
            self.script.plugin = self
            return

    def part(self, nick, mask, channel):
        if nick == self.bot.nick:
            self.connection_lost()
            return
        self.command_users.discard(nick)
        self.chat_users.discard(nick)

    def quit(self, nick, mask, channel):
        self.part(nick, mask, channel)

    @irc3.event('^:\S+ 353 [^&#]+(?P<channel>\S+) :(?P<nicknames>.*)')
    def names(self, channel=None, nicknames=None):
        # RPL_NAMREPLY
        nicknames = nicknames.split()
        for nick in nicknames:
            mode = nick[0]
            nick = nick[1:]
            try:
                self.mode_dict[mode].add(nick)
            except KeyError:
                continue

    @irc3.event(irc3.rfc.NEW_NICK)
    def new_nick(self, nick=None, new_nick=None, **kw):
        if nick in self.command_users:
            self.command_users.discard(nick)
            self.command_users.add(new_nick)
        if nick in self.chat_users:
            self.chat_users.discard(nick)
            self.chat_users.add(new_nick)

    @irc3.event(':(?P<mask>\S+) MODE (?P<channel>\S+)(\s+:(?P<data>.*)|$)')
    def on_mode(self, mask, channel, data):
        params = data.split(' ')
        modes, names = params[0], params[1:]

        if modes[0] not in '-+':
            modes = '+' + modes

        if channel == self.bot.nick:
            return

        for c in modes:
            if c in '-+':
                sign = c
                continue
            name = names.pop(0)
            try:
                users = self.mode_dict[c]
            except KeyError:
                continue
            if sign == '+':
                users.add(name)
            else:
                users.discard(name)

    def send(self, msg):
        self.bot.privmsg(self.script.channel, msg)

    def me(self, msg):
        msg = 'ACTION ' + msg
        self.bot.ctcp(self.script.channel, msg)


class IRCScriptConnection(ConnectionScript):
    def on_join(self, event):
        self.parent.send('* %s entered the game' % self.connection.name)

    def on_unload(self):
        if not self.connection.has_joined:
            return
        self.parent.send('* %s disconnected' % self.connection.name)

    def on_chat(self, event):
        message = '<\x0306%s\x0F> %s' % (self.connection.name, event.message)
        self.parent.send(message)


def unpack_modes(value):
    return {item for sublist in value for item in sublist}


class IRCScriptServer(ServerScript):
    connection_class = IRCScriptConnection
    plugin = None

    def on_load(self):
        config = self.server.config
        self.config = irc = config.irc

        self.command_modes = unpack_modes(irc.command_modes)
        self.chat_modes = unpack_modes(irc.chat_modes)

        self.channel = irc.channel.lower()
        if not self.channel.startswith('#'):
            self.channel = '#' + self.channel

        plugins = [
            'irc3.plugins.core',
            'irc3.plugins.autojoins',
            __name__
        ]

        bot = irc3.IrcBot(nick=irc.nickname, autojoins=[self.channel],
                          host=irc.server, port=irc.port, ssl=False,
                          includes=plugins, script=self)
        bot.create_connection()

    def on_unload(self):
        # XXX implement unload
        pass

    def send(self, *arg, **kw):
        if self.plugin is None:
            return
        self.plugin.send(*arg, **kw)

    def me(self, *arg, **kw):
        if self.plugin is None:
            return
        self.plugin.me(*arg, **kw)


def get_class():
    return IRCScriptServer


def irc(func):
    ServerPlugin.commands[func.__name__] = func
    return func


@irc
def who(bot):
    """
    Reimplemented here for the purpose of coloring the chat
    """
    server = bot.server
    player_count = len(server.players)
    if player_count == 0:
        bot.me('has no players connected')
        return
    formatted_names = []
    for player in list(server.players.values()):
        name = '\x0302%s #%s' % (player.name, player.entity_id)
        formatted_names.append(name)
    noun = 'player' if player_count == 1 else 'players'
    msg = 'has %s %s connected: ' % (player_count, noun)
    msg += '\x0F, '.join(formatted_names)
    bot.me(msg)
