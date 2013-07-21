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

from cuwo.script import ServerScript, command, get_player, admin
from cuwo.common import get_chunk
from cuwo.packet import HitPacket, HIT_NORMAL
from cuwo.vector import Vector3
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
def whereis(script, name=None):
    if name is None:
        player = script.connection
        message = 'You are at %s'
    else:
        player = get_player(script.server, name)
        message = '%s is at %%s' % player.name
    return message % (get_chunk(player.position),)


@command
def pm(script, name, *args):
    player = get_player(script.server, name)
    message = ' '.join(args)
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
def kill(script, name):
    player = get_player(script.server, name)
    damage_player(script, player, damage=player.entity_data.hp + 100.0)
    message = '%s was killed' % player.name
    print message
    script.server.send_chat(message)


@command
@admin
def stun(script, name, stun_duration=500):
    player = get_player(script.server, name)
    damage_player(script, player, stun_duration=stun_duration)
    message = '%s was stunned' % player.name
    print message
    script.server.send_chat(message)

#added who command
#based on irc version
#useful for players in games with more than 4 players
@command
def who(bot):
    server = bot.server
    player_count = len(server.connections)
    if player_count == 0:        
        return ('no players connected') #not really possible
    formatted_names = []
    for connection in server.connections.values():
        name = '%s #%s' % (connection.name,
                                 connection.entity_id)
        formatted_names.append(name)
    noun = 'player' if player_count == 1 else 'players'
    msg = '%s %s connected: ' % (player_count, noun)
    msg += ', '.join(formatted_names)
    return msg


#added whowhere
#gives where info for every player in who
#probably could also be a special case of whereis
@command
def whowhere(bot):
    server = bot.server
    player_count = len(server.connections)
    if player_count == 0:        
        return ('no players connected') #not really possible
    formatted_names = []
    player_positions = []
    for connection in server.connections.values():
        player = get_player(bot.server, connection.name)
        name = '%s #%s %s' % (connection.name,
                                 connection.entity_id, get_chunk(player.position))
        formatted_names.append(name)
    noun = 'player' if player_count == 1 else 'players'
    msg = '%s %s connected: ' % (player_count, noun)
    msg += ', '.join(formatted_names)
    return msg


@command
@admin
#added heal command
#heals specified player or yourself if none specified for 10000hp
def heal(script, name=None):
    if name is None:
        player = script.connection
    else:
        player = get_player(script.server, name)
    damage_player(script, player, damage=(-10000)) #unsure how to get max hp
    message = '%s was healed' % player.name
    return message
