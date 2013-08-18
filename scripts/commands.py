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

from cuwo.script import ServerScript, command, admin
from cuwo.common import get_chunk
from cuwo.constants import CLASS_NAMES, CLASS_SPECIALIZATIONS
from cuwo.packet import HitPacket, HIT_NORMAL
from cuwo.vector import Vector3
import platform


class CommandServer(ServerScript):
    pass


def get_class():
    return CommandServer


@command
@admin
def say(script, *message):
    """Sends a global server message."""
    message = ' '.join(message)
    script.server.send_chat(message)


@command
def server(script):
    """Returns information about the server's platform."""
    msg = 'Server is running on %r' % platform.system()
    revision = script.server.git_rev
    if revision is not None:
        msg += ', revision %s' % revision
    return msg


@command
def login(script, password):
    """Logs in using the specified password."""
    password = password.lower()
    user_types = script.server.passwords.get(password, [])
    if not user_types:
        return 'Invalid password'
    script.connection.rights.update(user_types)
    return 'Logged in as %s' % (', '.join(user_types))


@command
def help(script, name=None):
    """Returns information about commands."""
    if name is None:
        commands = [item.name for item in script.get_commands()]
        commands.sort()
        return 'Commands: ' + ', '.join(commands)
    else:
        command = script.get_command(name)
        if command is None:
            return 'No such command'
        return command.get_help()


@command
@admin
def kick(script, name):
    """Kicks the specified player."""
    player = script.get_player(name)
    player.kick()


@command
@admin
def setclock(script, value):
    """Sets the time of day. Format: hh:mm."""
    try:
        script.server.set_clock(value)
    except ValueError:
        return 'Invalid clock specified'
    return 'Clock set to %s' % value


@command
def whereis(script, name=None):
    """Shows where a player is in the world."""
    player = script.get_player(name)
    if player is script.connection:
        message = 'You are at %s'
    else:
        message = '%s is at %%s' % player.name
    return message % (get_chunk(player.position),)


@command
def pm(script, name, *message):
    """Sends a private message to a player."""
    player = script.get_player(name)
    message = ' '.join(message)
    player.send_chat('%s (PM): %s' % (script.connection.name, message))
    return 'PM sent'


def damage_player(script, player, damage=0, stun_duration=0):
    packet = HitPacket()
    packet.entity_id = player.entity_id
    packet.target_id = player.entity_id
    packet.hit_type = HIT_NORMAL
    packet.damage = damage
    packet.critical = 1
    packet.stun_duration = stun_duration
    packet.something8 = 0
    packet.pos = player.position
    packet.hit_dir = Vector3()
    packet.skill_hit = 0
    packet.show_light = 0
    script.server.update_packet.player_hits.append(packet)


@command
@admin
def kill(script, name=None):
    """Kills a player."""
    player = script.get_player(name)
    damage_player(script, player, damage=player.entity_data.hp + 100.0)
    message = '%s was killed' % player.name
    print message
    script.server.send_chat(message)


@command
@admin
def stun(script, name, milliseconds=1000):
    """Stuns a player for a specified duration of time."""
    player = script.get_player(name)
    damage_player(script, player, stun_duration=int(milliseconds))
    message = '%s was stunned' % player.name
    print message
    script.server.send_chat(message)


@command
@admin
def heal(script, name=None, hp=1000):
    """Heals a player by a specified amount."""
    player = script.get_player(name)
    damage_player(script, player, damage=-int(hp))
    message = '%s was healed' % player.name
    return message


def who_where(script, include_where):
    server = script.server
    player_count = len(server.players)
    if player_count == 0:
        return 'No players connected'
    formatted_names = []
    for player in server.players.values():
        name = '%s #%s' % (player.name, player.entity_id)
        if include_where:
            name += ' %s' % (get_chunk(player.position),)
        formatted_names.append(name)
    noun = 'player' if player_count == 1 else 'players'
    msg = '%s %s connected: ' % (player_count, noun)
    msg += ', '.join(formatted_names)
    return msg


@command
def who(script):
    """Lists players."""
    return who_where(script, False)


@command
def whowhere(script):
    """Lists players and their locations."""
    return who_where(script, True)


@command
def player(script, name):
    """Returns information about a player."""
    player = script.get_player(name)
    entity = player.entity_data
    typ = entity.class_type
    klass = CLASS_NAMES[typ]
    spec = CLASS_SPECIALIZATIONS[typ][entity.specialization]
    level = entity.level
    return "'%s' is a lvl %s %s (%s)" % (player.name, level, klass, spec)


@command
def scripts(script):
    """Lists the currently loaded scripts."""
    return 'Scripts: ' + ', '.join(script.server.scripts.items)
