from cuwo.script import FactoryScript, ProtocolScript, command, get_player
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

@command
def teleport(script, name):
    player = get_player(script.factory, name)
    this = script.protocol.entity_data
    other = player.entity_data
    this.name = 'WOO'
    this.x = this.x - 100000
    this.y = this.y - 100000
    script.protocol.force_entity_update()