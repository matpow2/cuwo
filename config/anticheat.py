# Logging level 2 = Verbose, 1 = Default, or 0 = None
log_level = 2

# Logging to irc, same levels as above
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
cooldown_margin = 0.5

# Max times someone can break cooldowns in a row before he is kicked
# This should be 1 or above because wollay.
max_cooldown_strikes = 3

# distance from the target they are hitting, larger basically allows
# for more lag.
max_hit_distance = 2000000

# Number of times in a row a player can break the max hit distance before he
# gets kicked, this should probably always be above 1, since if someone would
# respawn instantly they can still take damage from people with even minor lag.
max_hit_distance_strikes = 5

# Amount of seconds someone can be in the air before being kicked for flying
max_air_time = 10

# Allowed margin between real max speed and perceived max speed
# (not yet implemented)
speed_margin = 1

# Amount of seconds difference between last_hit and receiving a hitpacket
# last_hit_margin * max_last_hit_time_catchup + max_last_hit_strikes
# should be less then 15
# for it to effective, the closer to 15 the less chance it will actually do
# something..
last_hit_margin = 3.0

# Times last hit will be caught up instead of a strike given
max_last_hit_time_catchup = 3

# Last hit gets checked every second, if its over the margin a strike will be
# given. This should be above 0 as last_hit could probably be updated BEFORE
# the hitpacket arrives.
max_last_hit_strikes = 3

# Amount of times someone can exceed the max hit counter difference in a row
max_hit_counter_strikes = 3

# Max difference between estimated hit counter and actual hit counter
max_hit_counter_difference = 4

# max times someones hp can exceed actual max hp, used to avoid kicks when
# switch items, and gaining above max hp from unholy spirits
max_max_hp_strikes = 4


log_message = "{playername}({ip}) was removed for: {reason}."
disconnect_message = "{name} - You are being removed for: {reason}."
