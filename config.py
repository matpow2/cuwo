# -*- coding: utf-8 -*- 

# Global server name
server_name = 'cuwo server'

# Max number of players on the server at once
max_players = 4

# Seed for the server
seed = 26879

# Time speed modifier, 1.0 is default
time_modifier = 1.0

# List of scripts to run on the server on startup.
# Consider turning on 'pvp', i.e. player versus player
scripts = ['commands', 'welcome', 'ban']

# Passwords used for rights management. Keys are passwords, and values are
# a list of user types under that password. Right now, only 'admin' is defined,
# but scripts can restrict their usage depending on the user type 
passwords = {
    'PASSWORDREPLACEME' : ['admin']
}

# Used by the welcome.py script. Sends a small welcome message to users,
# replacing %(server_name)s with the server name defined in this file.
welcome = ["Welcome to %(server_name)s!",
           "(server powered by cuwo)"]

# IRC script variables (enable by adding 'irc' to script list)
irc_nickname = 'cuwobot'
irc_server = 'irc.esper.net'
irc_port = 6667
irc_channel = '#cuwo.bots'
irc_password = None
irc_commandprefix = '.'
irc_chatprefix = '#'