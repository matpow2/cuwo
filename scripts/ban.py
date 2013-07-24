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

from cuwo.script import ServerScript, command, admin, get_player

SELF_BANNED = 'You are banned: {reason}'
PLAYER_BANNED = '{name} has been banned: {reason}'
DEFAULT_REASON = 'No reason specified'

DATA_NAME = 'banlist'


class BanServer(ServerScript):
    def on_load(self):
        self.ban_entries = self.server.load_data(DATA_NAME, {})

    def save_bans(self):
        self.server.save_data(DATA_NAME, self.ban_entries)

    def ban(self, ip, reason):
        self.ban_entries[ip] = reason
        self.save_bans()
        for connection in self.server.connections.copy():
            if connection.address.host != ip:
                continue
            name = connection.name
            if name is not None:
                connection.send_chat(SELF_BANNED.format(reason=reason))
            connection.disconnect()
            if name is None:
                continue
            message = PLAYER_BANNED.format(name=name, reason=reason)
            print message
            self.server.send_chat(message)

    def on_connection_attempt(self, event):
        try:
            reason = self.ban_entries[event.address.host]
        except KeyError:
            return
        return SELF_BANNED.format(reason=reason)


def get_class():
    return BanServer


@command
@admin
def ban(script, name, *args):
    player = get_player(script.server, name)
    reason = ' '.join(args) or DEFAULT_REASON
    script.parent.ban(player.address.host, reason)
