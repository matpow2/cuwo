from cuwo.script import (FactoryScript, ProtocolScript, command, get_player)
from twisted.internet.protocol import Protocol, Factory
from twisted.python import log
from twisted.internet import reactor, protocol
from cuwo.txws import WebSocketFactory
from twisted.web.server import Site
from twisted.web.static import File
import json


class WebProtocol(Protocol):
    def __init__(self, factory):
        self.factory = factory

    def connectionMade(self):
        self.factory.connections.append(self)

    def dataReceived(self, data):
        data = json.loads(data)
        print data
        if data['want'] == 'players':
            list = [[], [], [], []]
            for connection in self.factory.server.connections.values():
                print connection.entity_data.name
                list[0].append(connection.entity_data.name)
                list[1].append(connection.entity_data.character_level)
                list[2].append(connection.entity_data.class_type)
                list[3].append(connection.entity_data.specialization)
            print list
            players = {'response': 'players', 'names': list[0], 'levels': list[1], 'klass': list[2],
                       'specialz': list[3]}
            print players
            print json.dumps(players)
            self.transport.write(json.dumps(players))

        self.transport.write(json.dumps({'response': "This shit got serious"}))

    def connectionLost(self, reason):
        self.factory.connections.remove(self)


class WebFactory(Factory):
    def __init__(self, server):
        self.connections = []
        self.server = server

    def buildProtocol(self, addr):
        return WebProtocol(self)


class WebScriptProtocol(ProtocolScript):
    """
    def on_join(self):
        self.parent.send('* %s entered the game' % self.protocol.get_name())

    def on_unload(self):
        self.parent.send('* %s disconnected' % self.protocol.get_name())

    def on_chat(self, message):
        message = message.encode('ascii', 'replace')
        message = '<%s> %s' % (self.protocol.get_name(), message)
        self.parent.send(message)
    """


class WebScriptFactory(FactoryScript):
    protocol_class = WebScriptProtocol

    def on_load(self):
        print 'Web Script Server'
        self.connections = []
        reactor.listenTCP(8080, Site(File('../web')))
        self.web_factory = WebFactory(self.factory)
        reactor.listenTCP(8081, WebSocketFactory(self.web_factory))

    def on_unload(self):
    #TODO implement unload
        pass


def get_class():
    return WebScriptFactory
