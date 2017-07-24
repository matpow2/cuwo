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
Sends updates to a master server at a constant interval
"""

from cuwo.script import ServerScript
from cuwo.exceptions import InvalidData
import zlib
import json
import asyncio


# sends an update packet every 10 seconds
UPDATE_RATE = 10


class MasterProtocol(asyncio.DatagramProtocol):
    transport = None

    def connection_made(self, transport):
        self.transport = transport

    def datagram_received(self, data, addr):
        try:
            value = json.loads(zlib.decompress(data).decode('utf-8'))
        except (zlib.error, ValueError):
            self.on_bad_packet(addr)
            return
        self.on_packet(value, addr)

    def error_received(self, exc):
        print('Master error:', exc)

    def on_packet(self, data, addr):
        pass

    def send_packet(self, value, addr):
        if self.transport is None:
            return
        data = zlib.compress(json.dumps(value).encode('utf-8'))
        self.transport.sendto(data, addr)

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

    def __init__(self, server, address):
        self.server = server
        self.address = address

    def connection_made(self, transport):
        self.transport = transport
        self.task = asyncio.get_event_loop().create_task(self.send_loop())

    @asyncio.coroutine
    def send_loop(self):
        config = self.server.config.base
        data = ServerData()

        while True:
            data.name = config.server_name
            data.max = config.max_players
            data.ip = self.server.config.master.hostname
            data.players = len(self.server.players)
            data.mode = self.server.get_mode()
            self.send_packet(data.get(), self.address)
            yield from asyncio.sleep(UPDATE_RATE)

    def on_packet(self, data, addr):
        if data.get('ack', False):
            self.on_ack()

    def on_ack(self):
        if self.has_response:
            return
        self.has_response = True
        print('Received response from master server')


class MasterRelay(ServerScript):
    connection_class = None

    def on_load(self):
        self.loop.create_task(self.start())

    def on_unload(self):
        self.protocol.task.cancel()

    @asyncio.coroutine
    def start(self):
        config = self.server.config
        master = config.master
        remote = (master.server, master.port)
        local_port = config.base.port
        self.protocol = MasterClient(self.server, remote)
        yield from self.server.create_datagram_endpoint(lambda: self.protocol,
                                                        port=local_port)

    def on_new_connection(self, event):
        return


def get_class():
    return MasterRelay
