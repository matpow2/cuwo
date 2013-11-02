# -*- coding: utf-8 -*-

# IRC script variables (enable by adding 'irc' to script list)
nickname = 'cuwobot'
server = 'irc.esper.net'
password = None
port = 6667
channel = '#cuwo.bots'
channel_password = None
commandprefix = '.'
chatprefix = '#'

# User modes which are allowed to chat and use commands.
command_modes = [('@', 'o'), ('&', 'a'), ('~', 'q'), ('%', 'h')]

# User modes which are allowed to chat to the in-game server.
chat_modes = [('+', 'v')]

# User types that the IRC bot has. The available commands from other scripts
# are restricted by this list.
rights = ['admin', 'irc']
