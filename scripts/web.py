from cuwo.script import (FactoryScript, ProtocolScript, command, get_player)
from twisted.internet.protocol import Protocol, Factory
from twisted.python import log
from twisted.internet import reactor, protocol
from cuwo.txws import WebSocketFactory


class WebProtocol(Protocol):
    def __init__(self, factory):
        self.factory = factory

    def makeConnection(self, transport):
        self.factory.connections.append(self)
        print self.transport

    def dataReceived(self, data):
        log.msg(data)
        print self.transport

    def connectionLost(self, reason):
        self.factory.connections.remove(self)


class WebFactory(Factory):
    def __init__(self):
        self.connections = []

    def on_load(self):
        print 'Web Server'
        reactor.listenTCP(WebSocketFactory(WebFactory()))

    def on_unload(self):
       # TODO implement unload
        pass

    def emit_message(self, message):
        for connection in self.connections:
            connection.transport.write(message)

    def buildProtocol(self, addr):
        print addr
        return WebProtocol(self)

def get_class():
    return WebFactory
