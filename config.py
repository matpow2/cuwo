# -*- coding: utf-8 -*-

# Server id (maybe for future use to e.g. run multiple servers through multiplex proxy for (sub-)domain use)
server_id = 0

# Global server name
server_name = 'a Server powered by cuwo'

# World seed used for world generation (change if you want another landscape etc.)
# When changing this, the old world and its data gets lost.
seed = 1

# Password salt
# Change this to a random string value before starting cuwo the first time
# Do not change when users already have registered or they will not be able to login anymore
password_salt = 'cuwo'

# Players have to register swhen joining the server for the first time
# before being able to play and to get a login id (used for /login <id> <password>)
register_players = False

# Players need to login before being able to play
logon_enabled = False

# Enable/Disable auto update feature (not implemented yet)
auto_update = True

# Max number of players that are allowed on the server at once
max_players = 20

# AutoSleep mode
# Server pauses e.g. entities, calculation and limits functionality/speed
# for decreased ressource use when nobody is online
inactivity_auto_sleep = False

# Min/Max level to be able to join
join_level_min = 1
join_level_max = 2000

# Forbid some things if you want
forbid_races = []
forbid_items_use = []
forbid_items_possession = []
# Here you can  forbid entity types like Mobs or other NPCs
forbid_entity_types = []

# Default lifetime of items in seconds before they despawn (-1 means they will not despawn until restart)
max_item_lifetime = 60

# Maximum amount of items per chunk (-1 means unlimited but is not recommended)
max_items_per_chunk = 100

# Protections
spam_protection = True
grief_protection = True
# Very basic but low-ressource cheat protections (maybe use an additional and more advanced anticheat script)
cheat_protection = True
# Denial of Service protection (better use hardware doing this job)
protection_dos = True

# Enable/Disable auto kick on some things
auto_kick_spam = True
auto_kick_timeout = True

# Time speed modifier, 1.0 is default
time_modifier = 1.0

# List of scripts to run on the server on startup.
# Consider turning on 'pvp', i.e. player versus player
scripts = ['commands', 'welcome', 'pvp', 'ban', 'give']

# Passwords used for rights management. Keys are passwords, and values are
# a list of user types under that password. Right now, only 'admin' is defined,
# but scripts can restrict their usage depending on the user type
passwords = {
    'PASSWORDREPLACEME': ['admin']
}

# Used by the welcome.py script. Sends a small welcome message to users,
# replacing %(server_name)s with the server name defined in this file.
welcome = ["Welcome to %(server_name)s!",
           "Provided by cuwo - an Open-Source Cube World Server-Implementation licensed under GNU GPL 3.",
           "cuwo currently is in an early development state so not everything can work as expected yet.",
           "Player Commands: /help, /list, /spawn, /tell <player> <message>, /whois <player>, /whereis <player>",
           "This message and many other things can be changed as you want in the config.py file."]

# Command help provided to players
help_players = ["=== PLAYER COMMANDS HELP ===",
                "/register <password> - use this to get an unique id when joining the first time",
                "/login <id> <password> - login after joining using your numeric id you got on registering and the right password",
                "/spawn - teleports you to the spawn point",
                "/list - shows you who currently is online",
                "/whereis <player> - tells you who is where (coordinates)",
                "/tell <player> <message> - allows you to send a private message to the given player"]

# Web interface variables (enable by adding 'web' to script list)
web_port = 8081

# Profile file. Set to something other than None to enable.
profile_file = None
