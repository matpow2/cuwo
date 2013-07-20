# Copyright (c) Mathias Kaerlev 2013.
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

CLIENT_VERSION = 3

# Not really changable for clients yet
SERVER_PORT = 12345

# Speed of time goes by
MAX_TIME = 86400000.0
NORMAL_TIME_SPEED = 10.0
SLEEP_TIME_SPEED = 100.0

 # 25 is enough and more could affect traffic and/or cpu load negative
UPDATE_FPS = 25

# Default lifetime of items in seconds before they despawn (-1 means they will not despawn until restart)
MAX_ITEM_LIFETIME = 60
# Maximum amount of items per chunk (-1 means unlimited but is not recommended)
MAX_ITEMS_PER_CHUNK = 100

# USE ANTI CHEATING SYSTEM
ANTICHEAT_SYSTEM_ENABLED = True

# USE ANTI GRIEFING SYSTEM (not used nor implemented yet)
ANTIGRIEF_SYSTEM_ENABLED = True


BLOCK_SCALE = 0xFFFF
CHUNK_SCALE = 0xFFFFFF
SECTOR_SCALE = 0x3FFFFFFF

MAX_POS = 0xFFFFFFFFFF

ENTITY_TYPE_PLAYER_MIN_ID = 1
ENTITY_TYPE_PLAYER_MAX_ID = 16

# Human readable class names
PLAYER_CLASSES = ['Unknown','Warrior','Ranger','Mage','Rogue']

# Human readable race names
PLAYER_RACES = ['Unknown','Humans','Elves','Dwarves','Goblins','Lizardmen','Orcs','Undeads','Frogmen']

# Min/Max level to be able to join
LEVEL_MIN = 1
LEVEL_MAX = 10000

FORBIDDEN_RACES = []


FORBIDDEN_ITEMS = []

FORBIDDEN_ITEMS_USE = []
# Forbid item possession (e.g. when you have them in your inventory)
FORBIDDEN_ITEMS_POSSESSION = []
