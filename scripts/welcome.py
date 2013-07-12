from cuwo.script import FactoryScript, ProtocolScript, command
from twisted.internet import reactor

class WelcomeFactory(FactoryScript):
    protocol_script = None

    def on_load(self):
        self.welcome = self.factory.format_lines(self.factory.config.welcome)

    def on_new_connection(self, protocol):
        protocol.send_lines(self.welcome)

def get_class():
    return WelcomeFactory

@command
def testcmd(script):
    script.protocol.send_chat('TEST :))')