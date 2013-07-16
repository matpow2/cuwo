"""
Sends a welcome message to players
"""

from cuwo.script import FactoryScript, ProtocolScript, command
from twisted.internet import reactor

class WelcomeFactory(FactoryScript):
    protocol_class = None

    def on_load(self):
        print 'wellcome'
        self.welcome = self.factory.format_lines(self.factory.config.welcome)

    def on_new_connection(self, protocol):
        reactor.callLater(10, protocol.send_lines, self.welcome)

def get_class():
    return WelcomeFactory