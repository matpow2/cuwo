from cuwo.script import (FactoryScript, ProtocolScript, command, get_player)
from twisted.internet.protocol import Protocol, Factory
from twisted.python import log
from twisted.internet import reactor, protocol
from cuwo.txws import WebSocketFactory
from twisted.web import (resource,static)
from twisted.web.server import Site
from twisted.web.static import File
import json
import os


class WebProtocol(Protocol):
    def __init__(self, factory):
        self.factory = factory

    def connectionMade(self):
        self.factory.connections.append(self)

    def dataReceived(self, data):
        data = json.loads(data)
        if data['want'] == 'players':
            self.transport.write(self.factory.get_players())

        else:
            self.transport.write(json.dumps({'response': "This shit got serious"}))

    def connectionLost(self, reason):
        self.factory.connections.remove(self)


class WebFactory(Factory):
    def __init__(self, server):
        self.connections = []
        self.server = server

    def get_players(self):
        ##list = [names[],levels[],class[],[specializations[]]
        list = [[], [], [], []]
        for connection in self.server.connections.values():
            list[0].append(connection.entity_data.name)
            list[1].append(connection.entity_data.character_level)
            list[2].append(connection.entity_data.class_type)
            list[3].append(connection.entity_data.specialization)
        players = {'response': 'players', 'names': list[0], 'levels': list[1], 'klass': list[2], 'specialz': list[3]}
        return json.dumps(players)

    def buildProtocol(self, addr):
        return WebProtocol(self)


class WebScriptProtocol(ProtocolScript):

    def on_join(self):
        self.parent.update_web("players")

    def on_unload(self):
        self.parent.update_web("players")


class WebScriptFactory(FactoryScript):
    protocol_class = WebScriptProtocol

    def on_load(self):
        config = self.factory.config

        f = open('./web/js/init.js', 'w')
        f.write('var server_port = "%s"' % config.web_port2)
        root = File('./web')
        root.indexNames = ['index.html']
        root.putChild('css', static.File("./web/css"))
        root.putChild('js', static.File("./web/js"))
        root.putChild('img', static.File("./web/img"))

        reactor.listenTCP(config.web_port1, Site(root))
        self.web_factory = WebFactory(self.factory)
        reactor.listenTCP(config.web_port2, WebSocketFactory(self.web_factory))

    def update_web(self, entity):
        if entity == "players":
            for connection in self.web_factory.connections:
                connection.transport.write(self.web_factory.get_players())
            return
        pass


def get_class():
    return WebScriptFactory