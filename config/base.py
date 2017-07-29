# Global server name
server_name = 'cuwo server'

# Max number of players on the server at once.
max_players = 4

# Seed for the server
seed = 26879

# Time speed modifier, 1.0 is default
time_modifier = 1.0

# List of scripts to run on the server on startup.
# Consider turning both of the following scripts on: pvp, ctf
scripts = ['log', 'ddos', 'commands', 'welcome', 'ban', 'console', 'master',
           'anticheat']

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
console_log_format = '%(message)s'
file_log_format = '[%(asctime)s] %(message)s'

# World debug
world_debug_file = None

# Profile file. Set to something other than None to enable.
profile_file = None

# Max connections per IP to prevent DoS.
max_connections_per_ip = 5

# Connection timeout time in seconds
connection_timeout = 10.0

# Network interface to bind to. Defaults to all IPv4 interfaces.
network_interface = '0.0.0.0'

# Server port. Do not change this unless you have a modified client!
port = 12345

# Server send rate. Change this to a lower value for high-traffic servers.
# The vanilla server uses 50, but 20 or 25 may be more sensible.
update_fps = 50

# Enables terrain generation (depends on cuwo.tgen). This may not be needed
# for barebones PvP servers.
use_tgen = True

# Enables NPCs. Currently, only static NPCs work.
use_entities = True

# Number of seconds before a chunk is destroyed when no player has visited it
# for a while.
chunk_retire_time = 15.0

# Save data directory for storing e.g. ban information.
save_path = './save'