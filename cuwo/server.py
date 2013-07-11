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

from twisted.internet.protocol import Factory, Protocol
from twisted.internet import reactor
from twisted.internet.endpoints import TCP4ClientEndpoint
from bytes import ByteReader, ByteWriter, OutOfData
from printutility import PrintUtility
import zlib

packetlogfile=open('./packetLog.txt', 'w+')

class debug:
    packets_printed = 0
    max_packets = 4

class Packet(object):
    packet_id = None

    def read(self, reader):
        pass

    def write(self, writer):
        pass

    def get_size(self):
        return self.size

class ClientVersion(Packet):
    def read(self, reader):
        self.version = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.version)

class ServerFull(Packet):
    pass

class ServerMismatch(Packet):
    pass

class ServerData(Packet):
    def read(self, reader):
        if reader.read_uint32() != 0:
            print 'wierd server data'
            return
        self.entity_id = reader.read_uint64() # must be > 1 and < 10
        self.connection_data = reader.read(0x1168)

    def write(self, writer):
        writer.write_uint32(0)
        writer.write_uint64(self.entity_id)
        writer.write(self.connection_data)

class SeedData(Packet):
    def read(self, reader):
        self.seed = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.seed)    


class Server0(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        self.data = zlib.decompress(reader.read(size))
        
        datareader = ByteReader(self.data)
        
        self.entity = datareader.read_uint64()
        self.packetflags = datareader.read_uint64()
        
        
        packetlogfile.write("------------server packet0--------------\n")
        packetlogfile.write(("{0:b}".format(self.packetflags)) + "\n")
        packetlogfile.write(PrintUtility.to_hex(self.data))
        packetlogfile.write("\n----------------------------------------\n")
        
        
        
        
        
    def write(self, writer):
        data = zlib.compress(self.data)
        writer.write_uint32(len(data))
        writer.write(data)

class Client0(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        self.data = zlib.decompress(reader.read(size))
        
        datareader = ByteReader(self.data)
        
        self.entity = datareader.read_uint64()
        self.packetflags = datareader.read_uint64()
        
        packetlogfile.write("------------client packet0--------------\n")
        packetlogfile.write(("{0:b}".format(self.packetflags)) + "\n")
        packetlogfile.write(PrintUtility.to_hex(self.data))
        packetlogfile.write("\n----------------------------------------\n")

    def write(self, writer):
        data = zlib.compress(self.data)
        writer.write_uint32(len(data))
        writer.write(data)

class Unknown1(Packet):
    def read(self, reader):
        count = reader.read_uint32()
        self.items = []
        for i in xrange(count):
            something = reader.read_uint64()
            # breaks off here
            something2 = reader.read_uint64()
            # socket reads, as follows:
            # 24, 12, 12, 12, 12, 4, 4, 1, 4, 1, 4, 4, 4, 172, 2, 4, 4, 4, 4,
            # 4, 4, 1, 1, 4, 12, 12, 12, 4, 4, 4, 20, 1, 1, 4, 4, 8, 8, 1, 4,
            # 12, 24, 12, 1, 280, 3640, 16, 44, 4
            # sum: 4434
            data = reader.read(4434)
            self.items.append((something, something2, data))

    def write(self, writer):
        writer.write_uint32(len(self.items))
        for item in items:
            something, something2, data = item
            writer.write_uint64(something)
            writer.write_uint64(something2)
            writer.write(data)

class Unknown2(Packet):
    pass

class Unknown3(Packet):
    def read(self, reader):
        count = reader.read_uint32()
        self.data = reader.read(120 * count)

    def write(self, writer):
        writer.write_uint32(len(self.data) / 120)
        writer.write(self.data)

class Unknown4(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        self.data = reader.read(size) # zlib?

    def write(self, writer):
        writer.write_uint32(len(self.data))
        writer.write(self.data)

class Unknown5(Packet):
    def read(self, reader):
        self.something = reader.read_uint32()
        self.something2 = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.something)
        writer.write_uint32(self.something2)

class CWItemCustomizationBlock:
    xOffset = 0
    yOffset = 0
    zOffset = 0
    material = 0
    level = 0
    unknown = 0


class CWItem:
    amount = 0
    itemType = 0
    subType = 0
    unknown1 = 0
    modifier = 0
    unknown2 = 0
    rarity = 0
    adapted = 0
    level = 0
    customization = []
    customizationBlocksUsed = 0
    
class ItemFlags:
    adapted = 1
    flags = 0
    
    def __init__(self, itemflags):
        self.flags = itemflags
    
    def isAdapted(self, flags):
        return (flags & self.adapted) == self.adapted


class ItemPacket(Packet):
    item = CWItem()
    
    def read(self, reader):
        self.item.itemType = reader.read_uint8();
        self.item.subType = reader.read_uint8();
        self.item.unknown1 = reader.read_uint16();  # just padding?
        self.item.modifier = reader.read_uint32();
        self.item.unknown2 = reader.read_uint32();
        self.item.rarity = reader.read_uint8();
        self.item.material = reader.read_uint8();
        self.item.itemFlags = ItemFlags(reader.read_uint16());
        self.item.level = reader.read_uint16();
        self.item.unknown3 = reader.read_uint16();
        
        self.item.customization = []
        for i in range(32):
            block = CWItemCustomizationBlock()
            block.xOffset = reader.read_uint8();
            block.yOffset = reader.read_uint8();
            block.zOffset = reader.read_uint8();
            block.material = reader.read_uint8();
            block.level = reader.read_uint16();
            block.unknown = reader.read_uint16(); # just padding?
            
            self.item.customization.append(block)    
        
        self.item.customizationBlocksUsed = reader.read_uint32();

        self.data = reader.read(20)
        
        print PrintUtility.to_hex(data)

    def write(self, writer):
        writer.write_uint8(self.item.itemType)
        writer.write_uint8(self.item.subType)
        writer.write_uint16(self.item.unknown1)
        writer.write_uint32(self.item.modifier)
        writer.write_uint32(self.item.unknown2)
        writer.write_uint8(self.item.rarity)
        writer.write_uint8(self.item.material)
        writer.write_uint16(self.item.itemFlags.flags)
        writer.write_uint16(self.item.level)
        writer.write_uint16(self.item.unknown3)
        
        for block in self.item.customization:
            writer.write_uint8(block.xOffset)
            writer.write_uint8(block.yOffset)
            writer.write_uint8(block.zOffset)
            writer.write_uint8(block.material)
            writer.write_uint16(block.level)
            writer.write_uint16(block.unknown)
            
        writer.write_uint32(self.item.customizationBlocksUsed)
        
        writer.write(self.data)


class Vector3:
    x = 0
    y = 0
    z = 0

class HitPacket(Packet):
    hitLocation = Vector3()
    
    def read(self, reader):
        self.attackerEntityId = reader.read_uint64() # Entity ID doing the hitting
        self.targetEntityId = reader.read_uint64() # Entity ID of what was hit
        self.damageDealt = reader.read_float() # Negative numbers when getting healed      
        self.isCritical = reader.read_uint8() # 1 if critical
        reader.skip(3)
        self.stunDuration = reader.read_uint32() # stun duration in ms (if >0 stuns target for amount of ms)
        self.something8 = reader.read_uint32() # always 0
        self.hitLocation.x = reader.read_uint64()
        self.hitLocation.y = reader.read_uint64()
        self.hitLocation.z = reader.read_uint64()
        self.something15 = reader.read_uint32() # yea... not a clue, tried double\float\int32\int64, and none of it looks like it makes any sense to me.
        self.something16 = reader.read_uint32() # not a clue here either, seems so random.
        self.something17 = reader.read_uint32() # seems attack type related, every normal attack changes up to the point of max hitcombo, abilities give different numbers too, perhaps its mutiple things
        self.isSkillHit = reader.read_uint8() # is 1 when ever hit by a skill, like mouse2, or ability1
        self.isEvading = reader.read_uint8() # 3 when enemy is evading (misses, when mobs are unable to reach you), seen 4 once, not sure what happend, but its more then just evading
        self.something20 = reader.read_uint8() # always 0
        reader.skip(1)       
        
        # no clue always printing to figure it out.
        print "something15", self.something15
        print "something16", self.something16
        print "something17", self.something17
        
        # things im not sure about that are always one value or another
        # pay attention when these do show up    
        if self.something8 != 0:
            print "!! something8", self.something8
        if self.something20 != 0:
            print "!! something20", self.something20
                
        if self.isEvading != 0 and self.isEvading != 3:
            print "!! isEvading", self.isEvading
            
        if self.isSkillHit != 0 and self.isSkillHit != 1: 
            print "!! isSkillHit", self.isSkillHit
            
    def write(self, writer):
        writer.write_uint64(self.attackerEntityId)
        writer.write_uint64(self.targetEntityId)
        writer.write_float(self.damageDealt) 
        writer.write_uint8(self.isCritical)
        writer.pad(3)
        writer.write_uint32(self.stunDuration)
        writer.write_uint32(self.something8)
        writer.write_uint64(self.hitLocation.x)
        writer.write_uint64(self.hitLocation.y)
        writer.write_uint64(self.hitLocation.z)
        writer.write_uint32(self.something15)
        writer.write_uint32(self.something16)
        writer.write_uint32(self.something17)
        writer.write_uint8(self.isSkillHit)
        writer.write_uint8(self.isEvading)
        writer.write_uint8(self.something20)
        writer.pad(1)

class Unknown8(Packet):
    def read(self, reader):
        self.data = reader.read(40)

    def write(self, writer):
        writer.write(self.data)

class Unknown9(Packet):
    def read(self, reader):
        print 'SHOOT'
        self.data = reader.read(112)

    def write(self, writer):
        writer.write(self.data)

ENCODING = 'utf_16_le'

class ServerChatMessage(Packet):
    def read(self, reader):
        self.player_id = reader.read_uint64()
        size = reader.read_uint32()
        data = reader.read(size * 2)
        self.value = data.decode(ENCODING)

    def write(self, writer):
        writer.write_uint64(self.player_id)
        data = self.value.encode(ENCODING)
        writer.write_uint32(len(data) / 2)
        writer.write(data)

class ClientChatMessage(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        data = reader.read(size * 2)
        self.value = data.decode(ENCODING)

    def write(self, writer):
        data = self.value.encode(ENCODING)
        writer.write_uint32(len(data) / 2)
        writer.write(data)

class ClientReadChunk(Packet):
    def read(self, reader):
        self.x = reader.read_uint32()
        self.y = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.x)
        writer.write_uint32(self.y)

class Unknown12(Packet):
    # something to do with chunk-loading as well
    def read(self, reader):
        self.x = reader.read_uint32()
        self.y = reader.read_uint32()   

    def write(self, writer):
        writer.write_uint32(self.x)
        writer.write_uint32(self.y)

CS_PACKETS = {
    0 : Client0,
    6 : ItemPacket, # drop/pickup/interact
    7 : HitPacket, # hit enemy
    8 : Unknown8, # stealth
    9 : Unknown9, # shoot arrow
    10 : ClientChatMessage,
    11 : ClientReadChunk, # sent when client has loaded new chunk in memory
    12 : Unknown12, # related to chunk loading, uses the same routine as above
    17 : ClientVersion
}

SC_PACKETS = {
    0 : Server0,
    1 : Unknown1,
    2 : Unknown2,
    3 : Unknown3,
    4 : Unknown4,
    5 : Unknown5,
    10 : ServerChatMessage,
    18 : ServerMismatch,
    17 : ServerFull,
    16 : ServerData,
    15 : SeedData
}

def read_packet(reader, table):
    packet_id = reader.read_uint32()
    packet = table[packet_id]()
    packet.read(reader)
    return packet

def write_packet(packet):
    writer = ByteWriter()
    writer.write_uint32(packet.packet_id)
    packet.write(writer)
    return writer.get()

for table in (CS_PACKETS, SC_PACKETS):
    for k, v in table.iteritems():
        v.packet_id = k

class PacketHandler(object):
    data = ''

    def __init__(self, table, callback):
        self.table = table
        self.callback = callback

    def feed(self, data):
        self.data += data
        reader = ByteReader(self.data)
        while True:
            pos = reader.tell()
            if pos >= len(self.data):
                break
            try:
                packet = read_packet(reader, self.table)
            except OutOfData:
                break
            self.callback(packet)
        self.data = self.data[pos:]

class RelayClient(Protocol):
    def __init__(self, protocol):
        self.protocol = protocol

    def dataReceived(self, data):
        self.protocol.serverDataReceived(data)

class RelayFactory(Factory):
    def __init__(self, protocol):
        self.protocol = protocol

    def buildProtocol(self, addr):
        return RelayClient(self.protocol)

import collections

server_ids = collections.Counter()
client_ids = collections.Counter()

ignore_ids = (10, 16, 15)

class CubeWorldProtocol(Protocol):
    relay_client = None
    relay_packets = None

    def __init__(self, server):
        self.server = server
        self.client_handler = PacketHandler(CS_PACKETS,
                                            self.on_client_packet)
        self.server_handler = PacketHandler(SC_PACKETS,
                                            self.on_server_packet)
        self.relay_packets = []
        reactor.callLater(10, self.test)
        self.print_stats()

    def print_stats(self):
        return
        reactor.callLater(3, self.print_stats)
        print 'Server packets:', server_ids
        print 'Client packets:', client_ids 

    def test(self):
        lines = [u'Hello! Welcome to the server!',
                 u'(server powered by cuwo)']
        for line in reversed(lines):
            self.send_chat(line)

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.player_id = 0
        packet.value = value
        self.transport.write(write_packet(packet))

    def on_client_packet(self, packet):
        if packet.packet_id in (12, 11):
            return
        if self.relay_client is None:
            self.relay_packets.append(write_packet(packet))
            return
        self.relay_client.transport.write(write_packet(packet))
        client_ids[packet.packet_id] += 1
        if packet.packet_id in (0,):
            return
        print 'Got client packet:', packet.packet_id

    def on_server_packet(self, packet):
        self.transport.write(write_packet(packet))
        server_ids[packet.packet_id] += 1
        if packet.packet_id in (0, 2, 4, 5):
            return
        print 'Got server packet:', packet.packet_id

    def got_relay_client(self, p):
        self.relay_client = p
        for data in self.relay_packets:
            self.relay_client.transport.write(data)
        self.relay_packets = None

    def connectionMade(self):
        point = TCP4ClientEndpoint(reactor, "127.0.0.1", 12346)
        d = point.connect(RelayFactory(self))
        d.addCallback(self.got_relay_client)
        print 'Connected'

    def connectionLost(self, reason):
        if self.relay_client is not None:
            self.relay_client.transport.loseConnection()

    def serverDataReceived(self, data):
        self.server_handler.feed(data)

    def dataReceived(self, data):
        self.client_handler.feed(data)

class CubeWorldServer(Factory):
    def __init__(self):
        print 'cuwo running on port 12345'

    def buildProtocol(self, addr):
        return CubeWorldProtocol(self)

def main():
    reactor.listenTCP(12345, CubeWorldServer())
    reactor.run()

if __name__ == '__main__':
    main()