# Discord script variables (enable by adding 'discord' to script list)
token = None # bot token
channel_id = None # as a string, e.g. '1234568891'
command_prefix = '!'
chat_prefix = '.'

# User role names which are allowed to chat and use commands.
command_roles = ['admin']
chat_roles = ['@everyone']

# User types that the Discord bot has. The available commands from other
# scripts are restricted by this list.
rights = ['admin', 'discord']
