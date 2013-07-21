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
scripts = ['log', 'commands', 'welcome', 'ban']

# Passwords used for rights management. Keys are passwords, and values are
# a list of user types under that password. Right now, only 'admin' is defined,
# but scripts can restrict their usage depending on the user type
passwords = {
    'PASSWORDREPLACEME': ['admin']
}

# Used by the welcome.py script. Sends a small welcome message to users,
# replacing %(server_name)s with the server name defined in this file.
welcome = ["Welcome to %(server_name)s!",
           "(server powered by cuwo)"]

# Logging variables
log_name = './logs/log.txt'
rotate_daily = True

# Profile file. Set to something other than None to enable.
profile_file = None
