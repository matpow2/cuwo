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

# prtocol constants
CLIENT_VERSION = 3
SERVER_PORT = 12345

# time constants
MAX_TIME = 24 * 60 * 60 * 1000
NORMAL_TIME_SPEED = 10.0
SLEEP_TIME_SPEED = 100.0
UPDATE_FPS = 50  # 50FPS in the code, 100FPS when measured-- odd.

# scale constants
BLOCK_SCALE = 0xFFFF
CHUNK_SCALE = 0xFFFFFF
SECTOR_SCALE = 0x3FFFFFFF
MAX_POS = 0xFFFFFFFFFF

# class types
WARRIOR = 1
BERSERKER = 0
GUARDIAN = 1

RANGER = 2
SNIPER = 0
SCOUT = 1

MAGE = 3
FIRE_MAGE = 0
WATER_MAGE = 1

ROUGUE = 4
ASSASSIN = 0
NINJA = 1
