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

import sys

class InvalidPlayer(Exception):
    pass

class InsufficientRights(Exception):
    pass

def get_player(factory, value):
    ret = None
    try:
        if value.startswith('#'):
            value = int(value[1:])
            ret = factory.connections[value]
        else:
            connections = factory.connections
            try:
                ret = connections[value]
            except KeyError:
                value = value.lower()
                for player in connections.values():
                    name = player.entity_data.name.lower()
                    if name == value:
                        return player
                    if name.count(value):
                        ret = player
    except (KeyError, IndexError, ValueError):
        pass
    if ret is None:
        raise InvalidPlayer()
    return ret

def restrict(func, *user_types):
    def new_func(script, *arg, **kw):
        if script.protocol.rights.isdisjoint(user_types):
            raise InsufficientRights()
        return func(script, *arg, **kw)
    new_func.__module__ = func.__module__
    new_func.func_name = func.func_name
    return new_func

def admin(func):
    return restrict(func, 'admin')

class BaseScript(object):
    def on_load(self):
        pass

    def on_unload(self):
        pass

class ProtocolScript(BaseScript):
    def __init__(self, parent, protocol):
        self.parent = parent
        self.factory = parent.factory
        self.protocol = protocol
        protocol.scripts.append(self)
        parent.scripts.append(self)
        self.on_load()

    def on_disconnect(self):
        self.unload()

    def on_command(self, name, args):
        if self.parent.commands is None:
            return
        f = self.parent.commands.get(name, None)
        if f is None:
            return
        ret = None
        try:
            ret = f(self, *args)
        except InvalidPlayer:
            ret = 'Invalid player specified'
        except InsufficientRights:
            ret = 'Insufficient rights'
        except Exception, e:
            import traceback
            traceback.print_exc()
        if ret is not None:
            self.protocol.send_chat(ret)
        return False

    def unload(self):
        if self.parent is None:
            return
        self.protocol.scripts.remove(self)
        self.parent.scripts.remove(self)
        self.on_unload()
        self.parent = self.protocol = self.factory = None

class FactoryScript(BaseScript):
    protocol_class = ProtocolScript
    commands = None

    def __init__(self, factory):
        self.factory = factory
        factory.scripts.append(self)
        self.scripts = []
        self.on_load()
        for protocol in factory.connections:
            self.on_existing_connection(protocol)

    def on_new_connection(self, protocol):
        if self.protocol_class is None:
            return
        self.protocol_class(self, protocol)

    def on_existing_connection(self, protocol):
        if self.protocol_class is None:
            return
        self.protocol_class(self, protocol)

    def unload(self):
        if self.factory is None:
            return
        self.on_stop()
        self.factory.scripts.remove(self)
        for script in self.scripts[:]:
            script.unload()
        self.scripts = None
        self.factory = None

# decorators for commands
def command(func, klass = None, level = None):
    if klass is None:
        klass = sys.modules[func.__module__].get_class()
    if klass.commands is None:
        klass.commands = {}
    func.level = level
    klass.commands[func.func_name] = func
    return func