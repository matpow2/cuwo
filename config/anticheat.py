# Logging level 2 = Verbose, 1 = Default, or 0 = None
log_level = 2
# Logging to irc, same levels as above, not actually in, yet.
irc_log_level = 2

# Regex name filter, anyone that does not match this will be removed.
# currently all keys normally on a keyboard. cubeworld really isnt picky.
name_filter = "^[a-zA-Z0-9_!@#$%\^&*()\[\]|:;'.,/\-+ <>\\\"{}~`=?]{2,16}$"

# If we allow the dual wield bug (equiping a 2h and a 1h at the same time)
allow_dual_wield = False

# Max allowed level
# Even players who level up legitly while playing will be removed
level_cap = 1000

# Highest level rarity level allowed on items, 4 is gold
rarity_cap = 4

# Number of times someone can attack and switch glider before it gets caught
# If you put this too low people just gliding after attacking will get kicked
# But you might want to put it slightly higher if people are getting kicked
# that are playing normally.
# This is mainly to stop the boomerang glitch, but who knows what other skills
# you can reset by spamming glider.
glider_abuse_count = 5

# Margin of time that can be between actual cooldown readiness and received
# readiness. smaller means more accurate, but also more chance someone gets
# kicked if he lags.
cooldown_margin = 0.75

log_message = "{playername}({ip}) was removed for: {reason}."
disconnect_message = "{name} - You are being removed for: {reason}."
welcome_message = "{name} - No cheats detected! (yet)"
