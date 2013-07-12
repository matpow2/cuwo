from cuwo.script import FactoryScript, ProtocolScript, command
import platform

class CommandFactory(FactoryScript):
    def on_load(self):
        pass

    def on_unload(self):
        pass

def get_class():
    return CommandFactory

@command
def say(script, *args):
    message = ' '.join(args)
    script.protocol.send_chat(message)

@command
def server(script):
    return 'Server is running on %r' % platform.system()