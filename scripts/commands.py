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

from cuwo.script import (ServerScript, ConnectionScript, command, get_player, admin)
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
@admin
def kick(script, name):
    try:
        player = get_player(script.server, name)
        player.kick('Kicked by an Admin')
        return '[SUCCESS] Kicked %s' % name
    except:
        return '[EXCEPTION] Player could not be kicked!'

@command
@admin
def setclock(script, value):
    try:
        script.server.set_clock(value)
        return '[SUCCESS] Time set to %s' % value
    except ValueError:
        return '[EXCEPTION] Invalid value!'

@admin
@command
def spawnmob(script, value):
    try:
        entity = script.server.create_entity(value)
    except ValueError:
        return '[ERROR] Invalid value!'
    entity.position(script.connection.position())

@command
def spawn(script, name = None):
    if name is None:
        player = script.connection
    else:
        player = get_player(script.server, name)
    except ValueError:
        return '[ERROR] Invalid value!'
    player.entity_data.position.x = 0
    player.entity_data.position.y = 0

@command
def help(script):
    return 'Player Commands: /spawn, /list, /whereis <player>, /tell <player> <message>'

@command
def list(script):
    plrs = []
    for connection in script.server.connections.values():
        plrs.append(connection.entity_data.name)
    message = '[INFO] Online: %s' % (', '.join(plrs))
    return message

@command
def login(script, password):
    password = password.lower()
    user_types = script.server.passwords.get(password, [])
    if not user_types:
        return '[ERROR] Invalid password!'
    script.connection.rights.update(user_types)
    return '[SUCCESS] Logged in as %s' % (', '.join(user_types))

@command
def whois(script, name = None):
    if name is None:
        player = script.connection
    else:
        player = get_player(script.server, name)
    acwcstr = ['Unknown','Warrior','Ranger','Mage','Rogue']
    if player.entity_data.class_type >= 0 and player.entity_data.class_type <= 4:
        return '[INFO] %s is %s class level %s' % (player.name, acwcstr[player.entity_data.class_type], player.entity_data.character_level)

@command
def whereis(script, name = None):
    if name is None:
        player = script.connection
        message = '[INFO] You are at %s'
    else:
        player = get_player(script.server, name)
        message = '[INFO] %s is at %%s' % player.name
    return message % (get_chunk(player.position),)

@command
def tell(script, name = None, *args):
    if not name:
        return '[INFO] /tell <player> <message>'
    try:
        player = get_player(script.server, name)
        if player is script.connection:
            return '[ERROR] You can not tell messages back to yourself!'
        message = '[PM] {0} -> {1}: {2}'.format(script.connection.name, player.name, ' '.join(args))
        player.send_chat(message % player)
        return message % player
    except:
        pass
    return '[EXCEPTION] Could not tell'
