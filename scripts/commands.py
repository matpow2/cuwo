# Copyright (c) Mathias Kaerlev, Somer Hayter, sarcengm and Jakky89 2013.
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

from cuwo.script import ServerScript, command, admin
from cuwo.common import get_chunk
from cuwo.packet import HitPacket, HIT_NORMAL
from cuwo.vector import Vector3
from twisted.internet import reactor
import cuwo.database

import platform
import sys





def get_class():
    return CommandServer


@command
@admin
def say(script, *args):
    message = ' '.join(args)
    script.server.send_chat(message)


@command
@admin
def kick(script, name):
    try:
        player = script.get_player(name)
        if player:
            player.kick('Kicked by Admin')
            return '[SUCCESS] Kicked %s' % name
    except:
        pass
    return '[ERROR] Player %s could not be kicked!' % name


@command
@admin
def kill(script, name=None):
    player = script.get_player(name)
    player.kill(script.connection):
    return None


@command
@admin
def setclock(script, value):
    try:
        script.server.set_clock(value)
        return '[SUCCESS] Time set to %s' % value
    except ValueError:
        return '[EXCEPTION] Invalid value!'
    return '[ERROR] Time could not be set!'


@command
@admin
def spawnmob(script, value):
    try:
        entity = script.server.create_entity_data(value)
    except ValueError:
        return '[ERROR] Invalid value!'
    except:
        pass
    if script.connection.position:
        entity.position(script.connection.position.copy())
    return '[ERROR] Could not spawn mob!'


@command
@admin
def heal(script, name=None, heal_amount=None):
    player = script.get_player(name)
    player.heal(amount, '[INFO] You have been healed by admin')
    return 'Healed %s' % player.name


@admin
@command
def restart(script, delay=10, *args):
    try:
        delay = int(delay)
    except Exception:
        return
    reason = None
    if len(args) > 0:
        reason = ' '.join(args)
    # Todo: add scheduler function
    # reactor.callLater(10, 'restart', delay)


@admin
@command
def shutdown(script, delay=10, *args):
    try:
        delay = int(delay)
    except Exception:
        return
    reason = None
    if len(args) > 0:
        reason = ' '.join(args)
    # Todo: add scheduler function
    # reactor.callLater(10, 'shutdown', delay)


@command
def spawn(script):
    player = script.get_player(name)
    if player.teleport(0, 0, 0):
        return '[INFO] Teleported to spawn.'
    return '[ERROR] Could not teleport to spawn.'


@command
def help(script):
    return PLAYER_COMMANDS_HELP


@command
def list(script):
    plcount = len(script.server.connections)
    if plcount <= 0:
        return '[INFO] There are currently no players online.'
    plrs = []
     for player in server.players.values():
        player.append('%s (%s)' % (player.entity_data.name, common.get_entity_type_level_str(player.entity_data))
    return '[INFO] %s/%s players online: %s' % (plcount, config.max_players, ', '.join(plrs))


@command
def register(script, password)
    if not password:
        return '[INFO] Register with password to get your login id for future logins: /register <password>'
    reg_id = database.register_player(script.server.db_con, script.connection.entity_data.name, password)
    if reg_id:
        return '[REGISTRATION] Please note that you have to do /login %s %s now to log in.' % (reg_id, password)
    return '[ERROR] Could not register!'


@command
def login(script, id, password):
    if not id or not password:
        return '[INFO] Command to login with your ID and password: /login <ID> <password>'
    login_res = database.login_player(script.server.db_con, script.connection.entity_data.name, id, password)
    if not login_res:
        return '[LOGIN] Login failed!'
    else:
        return '[LOGIN] Successfully logged in!' % id)
    return '[ERROR] Invalid password!'


@command
def whois(script, name=None):
    player = script.get_player(name)
    if not player:
        return '[ERROR] Could not get player by that name: %s' % name
    return '[INFO] %s is %s' % (player.name, common.get_entity_type_level_str(player.entity_data))


@command
def tell(script, name=None, *args):
    if not name:
        return '[INFO] Command to tell something to a specific player: /tell <player> <message>'
    try:
        player = script.get_player(name)
        if player is script.connection:
            return '[ERROR] You can not tell messages back to yourself!'
        message = '%s -> %s: %s' % (script.connection.entity_data.name, player.entity_data.name, ' '.join(args))
        player.send_chat(message)
        return message
    except:
        pass
    return '[EXCEPTION] Could not tell message to %s!' % player.entity_data.name
