# Copyright (c) Mathias Kaerlev 2013-2014.
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

from cuwo.script import ServerScript, command, admin, alias
from cuwo.common import get_chunk
from cuwo import constants
from cuwo import static
from cuwo.vector import vec3, qvec3
import platform

MAX_STUN_TIME = 1000 * 60  # 60 seconds in milliseconds


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
        commands = sorted([item.name for item in script.get_commands()])
        return 'Commands: ' + ', '.join(commands)
    else:
        command = script.get_command(name)
        if command is None:
            return 'No such command'
        return command.get_help()


@command
@admin
def kick(script, name, *reason):
    """Kicks the specified player."""
    reason = ' '.join(reason) or 'No reason specified'
    player = script.get_player(name)
    player.kick(reason)


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


@command
@admin
def kill(script, name=None):
    """Kills a player."""
    player = script.get_player(name)
    player.entity.kill()
    message = '%s was killed' % player.name
    print(message)
    script.server.send_chat(message)


@command
@admin
def stun(script, name, milliseconds=1000):
    """Stuns a player for a specified duration of time."""

    # Limit the stun time to as too high values can crash the server.
    # Also disallow negative values just in case.
    milliseconds = abs(milliseconds)
    if milliseconds > MAX_STUN_TIME:
        err = 'Stun time is too long. Please specify a value lower than %d.'
        return err % MAX_STUN_TIME

    player = script.get_player(name)
    player.entity.damage(stun_duration=int(milliseconds))
    message = '%s was stunned' % player.name
    print(message)
    script.server.send_chat(message)


@command
@admin
def heal(script, name=None, hp=1000):
    """Heals a player by a specified amount."""
    player = script.get_player(name)
    player.entity.damage(-int(hp))
    message = '%s was healed' % player.name
    return message


def who_where(script, include_where):
    server = script.server
    player_count = len(server.players)
    if player_count == 0:
        return 'No players connected'
    formatted_names = []
    for player in list(server.players.values()):
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
    entity = player.entity
    typ = entity.class_type
    klass = constants.CLASS_NAMES[typ]
    spec = constants.CLASS_SPECIALIZATIONS[typ][entity.specialization]
    level = entity.level
    return '%r is a lvl %s %s (%s)' % (player.name, level, klass, spec)


@command
@admin
def addrights(script, player, *rights):
    """Gives rights to a user."""
    player = script.get_player(player)
    rights = set(rights) & player.rights
    player.rights.update(rights)
    if rights:
        rights = ', '.join((repr(right) for right in rights))
    else:
        rights = 'no'
    return '%s rights given to %r' % (rights, player.name)


@command
@admin
def removerights(script, player, *rights):
    """Removes rights from a user."""
    player = script.get_player(player)
    rights = set(rights) & player.rights
    player.rights.difference_update(rights)
    if rights:
        rights = ', '.join((repr(right) for right in rights))
    else:
        rights = 'no'
    return '%s rights removed from %r' % (rights, player.name)


@command
def rights(script, player=None):
    """Displays the rights of a user."""
    player = script.get_player(player)
    rights = player.rights
    if rights:
        rights = ', '.join((repr(right) for right in player.rights))
    else:
        rights = 'no'
    return '%r has %s rights' % (player.name, rights)


@command
@admin
def sound(script, name):
    """Plays a global sound."""
    try:
        script.server.play_sound(name)
    except KeyError:
        return 'No such sound'


def create_teleport_packet(pos, chunk_pos, user_id):
    packet = static.StaticEntityPacket()
    header = static.StaticEntityHeader()
    packet.header = header
    packet.chunk_x = chunk_pos[0]
    packet.chunk_y = chunk_pos[1]
    packet.entity_id = 0
    header.set_type('Bench')
    header.size = vec3(0, 0, 0)
    header.closed = True
    header.orientation = static.ORIENT_SOUTH
    header.pos = pos
    header.time_offset = 0
    header.something8 = 0
    header.user_id = user_id
    return packet


@command
@admin
@alias('t')
def teleport(script, a, b=None):
    """Teleport to a chunk or player."""
    entity = script.connection.entity

    if b is None:
        player = script.get_player(a)
        pos = player.entity.pos
    else:
        pos = qvec3(int(a), int(b), 0) * constants.CHUNK_SCALE
        pos.z = script.world.get_height(pos.xy) or entity.pos.z

    update_packet = script.server.update_packet
    chunk = script.connection.chunk

    packet = create_teleport_packet(pos, chunk.pos, entity.entity_id)
    update_packet.static_entities.append(packet)

    def send_reset_packet():
        if chunk.static_entities:
            chunk.static_entities[0].update()
        else:
            packet = create_teleport_packet(pos, chunk.pos, 0)
            update_packet.static_entities.append(packet)

    script.loop.call_later(0.1, send_reset_packet)


@command
@admin
def load(script, name):
    """Loads a script at runtime."""
    name = str(name)
    if name in script.server.scripts:
        return 'Script %r already loaded' % name
    script.server.load_script(name)
    return 'Script %r loaded' % name


@command
@admin
def unload(script, name):
    """Unloads a script at runtime."""
    name = str(name)
    if not script.server.unload_script(name):
        return 'Script %r is not loaded' % name
    return 'Script %r unloaded' % name


@command
@admin
def reload(script, name):
    """Reloads a script at runtime."""
    name = str(name)
    if not script.server.unload_script(name):
        return 'Script %r is not loaded' % name
    script.server.load_script(name, update=True)
    return 'Script %r reloaded' % name


@command
def scripts(script):
    """Lists the currently loaded scripts."""
    return 'Scripts: ' + ', '.join(script.server.scripts.items)
