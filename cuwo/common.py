# Copyright (c) Mathias Kaerlev, Somer Hayter and Julien Kross 2013.
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

from cuwo import constants

import shlex
import math
import os


def filter_string(value):
    # Cube World only displays characters between 32-126 (and \r\n which both
    # produce newlines) in-game, so in case the user sent a bogus message, we
    # need to filter out those characters and replace with spaces
    new = u''
    for c in value:
        o = ord(c)
        if o < 10 or (o > 13 and o < 32) or o > 255:
            c = u' '
        new += c
    return new


def get_hex_string(value):
    v = '0x'
    for c in value:
        new_hex = hex(ord(c))[2:].upper()
        if len(new_hex) < 2:
            new_hex = '0' + new_hex
        v += new_hex
    return v


def is_bit_set(mask, index):
    return mask & (1 << index)


def set_bit(mask, index, value):
    if value:
        mask |= 1 << index
    else:
        mask &= ~(1 << index)
    return mask


def get_bool_bitfield(mask):
    return [True if digit=='1' else False for digit in bin(mask)[2:]]


def get_clock_string(value):
    hour = (value * 24) / constants.MAX_TIME
    minute = ((value * 1440) / constants.MAX_TIME) % 60
    return '%02d:%02d' % (hour, minute)


def parse_clock(value):
    h, m = value.split(':')
    h = int(h)
    m = int(m)
    v = (h * constants.MAX_TIME) / 24 + (m * constants.MAX_TIME) / 1440
    return v


def get_chunk(vec):
    return (math.floor(vec.x / constants.CHUNK_SCALE),
            math.floor(vec.y / constants.CHUNK_SCALE))


def get_sector(vec):
    return (math.floor(vec.x / constants.SECTOR_SCALE),
            math.floor(vec.y / constants.SECTOR_SCALE))


def get_needed_xp(level):
    return math.floor((1050 * level - 50) / (level + 19))


def get_needed_total_xp(level):
    return math.floor(50 * (21 * (level - 1) + 400 * math.log(20) - 400 * math.log(19 + level)))


def get_xp_from_to(levelFrom, levelTo):
    return math.floor(50 * (21 * (levelTo - levelFrom) + 400 * math.log(19 + levelFrom) - 400 * math.log(19 + levelTo)))


def get_power_level(level):
    return math.floor(100 - 99 * ((1 + 0.0536) / (1 + 0.0536 * level)))


def get_player_race_str(race_id):
    return constants.PLAYER_RACES[race_id]


def get_player_class_str(class_id):
    return constants.PLAYER_CLASSES[class_id]


def parse_command(message):
    if isinstance(message, unicode):
        # due to shlex unicode problems
        message = message.encode('utf-8')
    try:
        args = shlex.split(message)
    except ValueError:
        args = message.split(' ')
    if args:
        command = args.pop(0)
    return command.decode('utf-8'), [arg.decode('utf-8') for arg in args]


def create_path(path):
    if path:
        try:
            print '[INFO] Creating directory structure to %s' % path
            os.makedirs(os.path.dirname(path))
            return True
        except OSError:
            print '[ERROR] Could not create directory structure to %s' % path
    return False


def create_file_path(path):
    return create_path(os.path.dirname(filename))


def open_create(filename, mode):
    if create_file_path(filename):
        print 'Creating file: %s' % filename
    return open(filename, mode)
