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
"""

from twisted.words.protocols import irc
from twisted.internet import reactor, protocol
from cuwo.common import parse_command
from cuwo.script import ServerScript, ConnectionScript, ScriptInterface


def channel(func):
    def new_func(self, user, channel, *arg, **kw):
        if not channel.lower() == self.factory.channel:
            return
        user = user.split('!', 1)[0]
        func(self, user, channel, *arg, **kw)
    return new_func

MAX_IRC_CHAT_SIZE = 100


def encode_irc(value):
    return value.encode('ascii', 'replace')


class IRCBot(irc.IRCClient):
    commands = {}

    def __init__(self, factory, server):
        self.server = server
        self.factory = factory
        self.nickname = factory.nickname
        self.password = factory.password
        self.channel_password = factory.channel_password
        self.interface = ScriptInterface('IRC', server, 'admin', 'irc')

        self.chat_users = set()
        self.command_users = set()
        self.user_dict = {}
        for symbol in factory.command_modes:
            self.user_dict[symbol] = self.command_users
        for symbol in factory.chat_modes:
            self.user_dict[symbol] = self.chat_users

    def reset_users(self):
        self.chat_users.clear()
        self.command_users.clear()

    def signedOn(self):
        self.join(self.factory.channel, self.factory.channel_password)

    def joined(self, channel):
        if channel.lower() == self.factory.channel:
            self.reset_users()
        print "Joined channel %s" % channel

    def irc_NICK(self, prefix, params):
        user = prefix.split('!', 1)[0]
        new_user = params[0]
        if user in self.command_users:
            self.command_users.discard(user)
            self.command_users.add(new_user)
        if user in self.chat_users:
            self.chat_users.discard(user)
            self.chat_users.add(new_user)

    def irc_RPL_NAMREPLY(self, *arg):
        if not arg[1][2].lower() == self.factory.channel:
            return
        for name in arg[1][3].split():
            mode = name[0]
            try:
                self.user_dict[mode].add(name[1:])
            except KeyError:
                pass

    def left(self, channel):
        if channel.lower() != self.factory.channel:
            return
        self.reset_users()

    @channel
    def modeChanged(self, user, channel, is_set, modes, args):
        for i in xrange(len(args)):
            mode, name = modes[i], args[i]
            try:
                l = self.user_dict[mode]
            except KeyError:
                continue
            if is_set:
                l.add(name)
            else:
                l.discard(name)

    @channel
    def privmsg(self, user, channel, msg):
        if user not in self.command_users and user not in self.chat_users:
            return
        prefix = '@' if user in self.command_users else '+'
        name = prefix + user
        if msg.startswith(self.factory.commandprefix):
            if user not in self.command_users:
                return
            cmd = msg[len(self.factory.commandprefix):]
            result = self.handle_command(name, cmd)
            if result is None:
                return
            self.send("%s: %s" % (user, result))
        elif msg.startswith(self.factory.chatprefix):
            msg = msg[len(self.factory.chatprefix):].strip()
            message = ("<%s> %s" % (name, msg))
            message = message[:MAX_IRC_CHAT_SIZE]
            print message
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

    @channel
    def userLeft(self, user, channel):
        self.command_users.discard(user)
        self.chat_users.discard(user)

    def userQuit(self, user, message):
        self.userLeft(user, self.factory.channel)

    def userKicked(self, kickee, channel, kicker, message):
        self.userLeft(kickee, channel)

    def send(self, msg):
        self.msg(self.factory.channel, encode_irc(msg))

    def me(self, msg):
        self.describe(self.factory.channel, encode_irc(msg))


def unpack_modes(value):
    return set([item for sublist in value for item in sublist])


class IRCClientFactory(protocol.ClientFactory):
    lost_reconnect_delay = 20
    failed_reconnect_delay = 60
    bot = None

    def __init__(self, server, config):
        self.server = server
        irc = config.irc
        self.nickname = irc.nickname
        self.username = 'cuwo'
        self.realname = config.base.server_name
        self.channel = irc.channel.lower()
        if not self.channel.startswith('#'):
            self.channel = '#' + self.channel
        self.commandprefix = irc.commandprefix
        self.chatprefix = irc.chatprefix
        self.password = irc.password
        self.channel_password = irc.channel_password
        self.rights = irc.rights
        self.command_modes = unpack_modes(irc.command_modes)
        self.chat_modes = unpack_modes(irc.chat_modes)

    def startedConnecting(self, connector):
        print "Connecting to IRC server..."

    def clientConnectionLost(self, connector, reason):
        print "Lost connection to IRC server (%s), " \
              "reconnecting in %s seconds" % (reason,
                                              self.lost_reconnect_delay)
        reactor.callLater(self.lost_reconnect_delay, connector.connect)

    def clientConnectionFailed(self, connector, reason):
        print "Could not connect to IRC server (%s), " \
              "retrying in %s seconds" % (reason, self.failed_reconnect_delay)
        reactor.callLater(self.failed_reconnect_delay, connector.connect)

    def buildProtocol(self, address):
        self.bot = IRCBot(self, self.server)
        return self.bot


class IRCScriptConnection(ConnectionScript):
    def on_join(self, event):
        self.parent.send('* %s entered the game' % encode_irc(
            self.connection.name))

    def on_unload(self):
        if not self.connection.has_joined:
            return
        self.parent.send('* %s disconnected' % encode_irc(
            self.connection.name))

    def on_chat(self, event):
        message = encode_irc('<\x0306%s\x0F> %s' % (
            self.connection.name, event.message))
        self.parent.send(message)


class IRCScriptServer(ServerScript):
    connection_class = IRCScriptConnection

    def on_load(self):
        config = self.server.config
        self.client_factory = IRCClientFactory(self.server, config)
        self.server.connect_tcp(config.irc.server, config.irc.port,
                                self.client_factory)

    def on_unload(self):
        # XXX implement unload
        pass

    def send(self, *arg, **kw):
        if self.client_factory.bot is None:
            return
        self.client_factory.bot.send(*arg, **kw)

    def me(self, *arg, **kw):
        if self.client_factory.bot is None:
            return
        self.client_factory.bot.me(*arg, **kw)


def get_class():
    return IRCScriptServer


def irc(func):
    IRCBot.commands[func.func_name] = func
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
    for player in server.players.values():
        name = '\x0302%s #%s' % (encode_irc(player.name), player.entity_id)
        formatted_names.append(name)
    noun = 'player' if player_count == 1 else 'players'
    msg = 'has %s %s connected: ' % (player_count, noun)
    msg += '\x0F, '.join(formatted_names)
    bot.me(msg)
