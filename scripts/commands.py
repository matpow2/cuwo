from cuwo.script import FactoryScript, ProtocolScript, command

class CommandFactory(FactoryScript):
    def on_load(self):
        pass

    def on_unload(self):
        pass

def get_class():
    return CommandFactory

@command
def test(script):
    script.protocol.send_chat('TEST :))')