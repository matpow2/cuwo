# Copyright (c) Mathias Kaerlev, Somer Hayter and Julien Kross 2013.
#
#
# This file is part of cuwo.
#
#
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
#
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
#
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.


# These constants are used without getting modified while the server is running
# and they are not intended to be changed very often by server administrators
# For general configuration please feel free to edit the config.py in the
# servers root folder as you like


# Version of clients that should be able to join
CLIENT_VERSION = 3


# Not really changable clientside yet
SERVER_PORT = 12345


# Time constants
MAX_TIME = 86400000.0
NORMAL_TIME_SPEED = 10.0
SLEEP_TIME_SPEED = 100.0
# 25 is enough and more could result in more traffic and/or cpu load
UPDATE_FPS = 25


# Client norecv packet timeout
CLIENT_RECV_TIMEOUT = 3


# Client antispam cooldown in seconds
ANTISPAM_LIMIT_CHAT = 1
# Burst means how many messages are acceptable within the limit
ANTISPAM_BURST_CHAT = 3


# Scale constants
BLOCK_SCALE = 0xFFFF
CHUNK_SCALE = 0xFFFFFF
SECTOR_SCALE = 0x3FFFFFFF
MAX_POS = 0xFFFFFFFFFF


# Entity types valid for players
ENTITY_TYPE_PLAYER_MIN_ID = 1
ENTITY_TYPE_PLAYER_MAX_ID = 16

# Entity classes valid for players
ENTITY_CLASS_PLAYER_MIN_ID = 1
ENTITY_CLASS_PLAYER_MAX_ID = 4

# Needed e.g. for anti cheating system
PLAYER_MAX_HEALTH = 300
PLAYER_MAX_LEVEL = 3000

# Human readable class names ordered by class id
PLAYER_CLASSES = ['Unknown','Warrior','Ranger','Mage','Rogue']

# Human readable race names ordered by race id
PLAYER_RACES = ['Unknown','Humans','Elves','Dwarves','Goblins','Lizardmen','Orcs','Undeads','Frogmen']
