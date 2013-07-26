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
Sends updates to a master server at a constant interval
"""

from cuwo.script import ServerScript
from cuwo.exceptions import InvalidData
from twisted.internet.protocol import DatagramProtocol
from twisted.internet.task import LoopingCall
from twisted.internet import reactor
import zlib
import json


# sends an update packet every 20 second
UPDATE_RATE = 10


class MasterProtocol(DatagramProtocol):
    def datagramReceived(self, data, addr):
        try:
            value = json.loads(zlib.decompress(data))
        except (zlib.error, ValueError):
            self.on_bad_packet(addr)
        self.on_packet(value, addr)

    def on_packet(self, data, addr):
        pass

    def send_packet(self, value, addr):
        if self.transport is None:
            return
        data = zlib.compress(json.dumps(value))
        self.transport.write(data, addr)

    def on_bad_packet(self, addr):
        pass


class ServerData(object):
    location = None
    ip = None

    def __init__(self, data=None):
        if data is None:
            return
        try:
            self.name = data.pop('name')
            self.max = data.pop('max')
            self.players = data.pop('players')
            self.mode = data.pop('mode')
            self.ip = data.pop('ip', None)
        except KeyError:
            raise InvalidData()
        if data:
            # some data was left over
            raise InvalidData()

    def get(self):
        data = {}
        data['name'] = self.name
        data['max'] = self.max
        data['players'] = self.players
        data['mode'] = self.mode
        if self.location is not None:
            data['location'] = self.location
        if self.ip is not None:
            data['ip'] = self.ip
        return data


class MasterClient(MasterProtocol):
    has_response = False

    def __init__(self, server, addr):
        self.server = server
        self.address = addr
        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(UPDATE_RATE)

    def update(self):
        config = self.server.config.base
        data = ServerData()
        data.name = config.server_name
        data.max = config.max_players
        data.ip = self.server.config.master.hostname
        data.players = len(self.server.players)
        data.mode = self.server.get_mode()
        self.send_packet(data.get(), self.address)

    def on_packet(self, data, addr):
        if data.get('ack', False):
            self.on_ack()

    def on_ack(self):
        if self.has_response:
            return
        self.has_response = True
        print 'Received response from master server'


class MasterRelay(ServerScript):
    connection_class = None

    def on_load(self):
        master = self.server.config.master
        reactor.resolve(master.server).addCallback(self.on_ip)

    def on_ip(self, ip):
        master = self.server.config.master
        config = self.server.config.base
        self.client = MasterClient(self.server, (ip, master.port))
        self.server.listen_udp(config.port, self.client)

    def on_new_connection(self, event):
        return


def get_class():
    return MasterRelay
