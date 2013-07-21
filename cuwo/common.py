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

from cuwo import constants

import shlex
import os


CHAR_FILTER = set([10, 13] + range(32, 127))

def filter_string(value):
    # Cube World only displays characters between 32-126 (and \r\n which both
    # produce newlines) in-game, so in case the user sent a bogus message, we
    # need to filter out those characters and replace with spaces
    new = u''
    for c in value:
        if ord(c) not in CHAR_FILTER:
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


def get_clock_string(value):
    hour = (value * 24) / constants.MAX_TIME
    minute = ((value * 24 * 60) / constants.MAX_TIME) % 60
    return '%02d:%02d' % (hour, minute)


def parse_clock(value):
    h, m = value.split(':')
    h = int(h)
    m = int(m)
    v = (h * constants.MAX_TIME) / 24 + (m * constants.MAX_TIME) / (24 * 60)
    return v


def get_chunk(vec):
    return (int(vec.x / constants.CHUNK_SCALE),
            int(vec.y / constants.CHUNK_SCALE))


def get_sector(vec):
    return (int(vec.x / constants.SECTOR_SCALE),
            int(vec.y / constants.SECTOR_SCALE))


def parse_command(message):
    if isinstance(message, unicode):
        # due to shlex unicode problems
        message = message.encode('utf-8')
    try:
        args = shlex.split(message)
    except ValueError:
        # shlex failed. let's just split per space
        args = message.split(' ')
    if args:
        command = args.pop(0)
    else:
        command = ''
    return command.decode('utf-8'), [arg.decode('utf-8') for arg in args]


def create_path(path):
    if path:
        try:
            os.makedirs(path)
        except OSError:
            pass


def create_file_path(path):
    create_path(os.path.dirname(path))


def open_create(filename, mode):
    create_file_path(filename)
    return open(filename, mode)
