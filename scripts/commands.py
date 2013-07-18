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

"""
Default set of commands bundled with cuwo
"""

from cuwo.script import (ServerScript, ConnectionScript, command, get_player,
    admin)
from cuwo.common import get_chunk
import platform

class CommandServer(ServerScript):
    pass

def get_class():
    return CommandServer

@command
@admin
def say(script, *args):
    message = ' '.join(args)
    script.connection.send_chat(message)

@command
def server(script):
    msg = 'Server is running on %r' % platform.system()
    revision = script.server.git_rev
    if revision is not None:
        msg += ', revision %s' % revision
    return msg

@command
def login(script, password):
    password = password.lower()
    user_types = script.server.passwords.get(password, [])
    if not user_types:
        return 'Invalid password'
    script.connection.rights.update(user_types)
    return 'Logged in as %s' % (', '.join(user_types))

@command
@admin
def kick(script, name):
    player = get_player(script.server, name)
    player.kick()

@command
@admin
def setclock(script, value):
    try:
        script.server.set_clock(value)
    except ValueError:
        return 'Invalid clock specified'
    return 'Clock set to %s' % value

@command
def whereis(script, name = None):
    if name is None:
        player = script.connection
        message = 'You are at %s'
    else:
        player = get_player(script.server, name)
        message = '%s is at %%s' % player.name
    return message % (get_chunk(player.position),)

