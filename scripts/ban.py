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
Ban management
"""

from cuwo.script import (FactoryScript, ProtocolScript, command, admin,
    get_player)
from twisted.internet import reactor

SELF_BANNED = 'You are banned: {reason}'
PLAYER_BANNED = '{name} has been banned: {reason}'
DEFAULT_REASON = 'No reason specified'

DATA_NAME = 'banlist'

class BanFactory(FactoryScript):
    def on_load(self):
        self.ban_entries = self.factory.load_data(DATA_NAME, {})

    def save_bans(self):
        self.factory.save_data(DATA_NAME, self.ban_entries)

    def ban(self, ip, reason):
        self.ban_entries[ip] = reason
        self.save_bans()
        for connection in self.factory.connections.values().copy():
            if connection.address.host != ip:
                continue
            name = connection.name
            if name is not None:
                connection.send_chat(SELF_BANNED.format(reason = reason))
            connection.disconnect()
            self.factory.send_chat(PLAYER_BANNED.format(name = name, 
                                                        reason = reason))

    def on_connection_attempt(self, addr):
        try:
            reason = self.ban_entries[addr.host]
        except KeyError:
            return
        return SELF_BANNED.format(reason = reason)

def get_class():
    return BanFactory

@command
@admin
def ban(script, name, *args):
    player = get_player(script.factory, name)
    reason = ' '.join(args) or DEFAULT_REASON
    script.parent.ban(player.address.host, reason)