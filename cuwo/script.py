# Copyright (c) Mathias Kaerlev 2013-2014.
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

from cuwo.types import AttributeSet, AttributeDict
import collections
import sys
import inspect


class InvalidPlayer(Exception):
    pass


class InsufficientRights(Exception):
    pass


def get_player(server, value):
    ret = None
    players = server.players
    try:
        if value.startswith('#'):
            value = int(value[1:])
            return players[value]
        try:
            return players[value]
        except KeyError:
            pass
        value = value.lower()
        for player in players.values():
            name = player.name.lower()
            if name == value:
                return player
            if name.count(value):
                ret = player
    except (KeyError, IndexError, ValueError):
        pass
    if ret is None:
        raise InvalidPlayer()
    return ret


# command decorators/class implementation

class Command(object):
    def __init__(self, func):
        self.func = func
        self.original = original = getattr(func, 'func', func)
        self.name = original.func_name
        self.module = original.__module__
        self.user_types = getattr(original, 'user_types', None)
        self.doc = original.__doc__
        self.__call__ = func

        # parse function object information

        # get min args
        func_info = inspect.getargspec(original)
        self.min_args = len(func_info.args) - 1
        if not func_info.defaults is None:
            self.min_args -= len(func_info.defaults)

    def __call__(self, *arg, **kw):
        return self.func(*arg, **kw)

    def is_compatible(self, rights):
        if self.user_types is None:
            return True
        return not rights.isdisjoint(self.user_types)

    def get_help(self):
        syntax = self.get_syntax()
        if self.doc is None:
            return syntax
        return "%s\n%s" % (self.doc, syntax)

    def get_syntax(self):
        func_info = inspect.getargspec(self.original)
        has_defaults = func_info.defaults is not None
        if has_defaults:
            defaults_start = len(func_info.args) - len(func_info.defaults)
        arguments = [self.name]
        for i in xrange(1, len(func_info.args)):
            argument = func_info.args[i]
            if not has_defaults:
                arguments.append(argument)
                continue
            defaults_index = i - defaults_start
            if defaults_index >= 0:
                default = func_info.defaults[defaults_index]
                if default is None:
                    arguments.append('[%s]' % argument)
                else:
                    arguments.append('[%s=%s]' % (argument, default))
                continue
            arguments.append(argument)
        if func_info.varargs is not None:
            arguments.append('[%s]' % func_info.varargs)
        return 'Syntax: /' + ' '.join(arguments)


def command(func, klass=None):
    command = Command(func)
    if klass is None:
        klass = sys.modules[command.module].get_class()
    if klass.commands is None:
        klass.commands = {}
    klass.commands[command.name] = command
    return func


def restrict(*user_types):
    """Restricts the command to certain user types."""
    def dec(func):
        def new_func(script, *arg, **kw):
            if script.connection.rights.isdisjoint(user_types):
                raise InsufficientRights()
            return func(script, *arg, **kw)
        original = getattr(func, 'func', func)
        original.user_types = user_types
        new_func.func = original
        return new_func
    return dec


# decorator to restrict the use of commands to administrators only
admin = restrict('admin')


class ScriptManager(object):
    """Manages scripts for either a server or connection."""

    def __init__(self):
        self.items = collections.OrderedDict()
        self.cached_calls = {}

    def __getattr__(self, name):
        return self.items[name]

    def __getitem__(self, name):
        return self.items[name]

    def __contains__(self, name):
        return name in self.items

    def add(self, script):
        self.items[script.script_name] = script
        self.cached_calls.clear()

    def remove(self, script):
        del self.items[script.script_name]
        self.cached_calls.clear()

    def unload(self):
        for script in self.items.values():
            script.unload()

    def get(self):
        return self.items.itervalues()

    def call(self, event_name, **kw):
        try:
            handlers = self.cached_calls[event_name]
        except KeyError:
            handlers = []
            for script in self.items.values():
                f = getattr(script, event_name, None)
                if not f:
                    continue
                handlers.append(f)
            self.cached_calls[event_name] = handlers

        event = AttributeDict(kw)
        for handler in handlers:
            ret = handler(event)
            if ret is None:
                continue
            event.result = ret
            break
        else:
            event.result = None
        return event


class BaseScript(object):
    def call(self, event_name, **kw):
        event = AttributeDict(kw)
        f = getattr(self, event_name, None)
        if f is None:
            return
        event.result = f(event)
        return event

    def on_load(self):
        pass

    def on_unload(self):
        pass

    def unload(self):
        pass


class ConnectionScript(BaseScript):
    def __init__(self, parent, connection):
        self.script_name = parent.script_name

        self.parent = parent
        self.server = parent.server
        self.connection = connection
        connection.scripts.add(self)
        parent.children.append(self)
        self.on_load()

    def on_disconnect(self, event):
        self.unload()

    def on_command(self, event):
        ret = self.parent.call_command(self, event.command, event.args)
        if ret is None:
            return
        if ret:
            self.connection.send_chat(ret)
        return False

    def get_player(self, name=None):
        if name is None:
            return self.connection
        return get_player(self.server, name)

    def get_commands(self):
        rights = self.connection.rights
        for command in self.server.get_commands():
            if command.is_compatible(rights):
                yield command

    def get_command(self, name):
        command = self.server.get_command(name)
        if not command:
            return
        if not command.is_compatible(self.connection.rights):
            return
        return command

    def unload(self):
        if self.parent is None:
            return
        self.connection.scripts.remove(self)
        self.parent.children.remove(self)
        self.on_unload()
        self.parent = self.connection = self.server = None


class ServerScript(BaseScript):
    connection_class = ConnectionScript
    commands = None

    def __init__(self, server):
        self.script_name = self.__module__.split('.')[1]

        self.server = server
        server.scripts.add(self)
        self.children = []
        self.on_load()
        for connection in server.connections:
            self.call('on_existing_connection', connection=connection)

    def on_new_connection(self, event):
        if self.connection_class is None:
            return
        script = self.connection_class(self, event.connection)
        script.call('on_connect')

    def on_existing_connection(self, event):
        if self.connection_class is None:
            return
        self.connection_class(self, event.connection)

    def on_command(self, event):
        return self.call_command(event.user, event.command, event.args)

    def unload(self):
        if self.server is None:
            return
        self.on_unload()
        self.server.scripts.remove(self)
        for script in self.children[:]:
            script.unload()
        self.children = None
        self.server = None

    def call_command(self, user, command, args):
        if self.commands is None:
            return
        command = self.commands.get(command.lower(), None)
        if not command:
            return
        user.parent = self  # for ScriptInterface

        if len(args) < command.min_args:
            return command.get_syntax()

        try:
            ret = command(user, *args) or ''
        except InvalidPlayer:
            ret = 'Invalid player specified'
        except InsufficientRights:
            ret = 'Insufficient rights'
        except Exception:
            import traceback
            traceback.print_exc()
            ret = ''
        return ret


class ScriptInterface(object):
    """
    Used for external script interfaces to emulate a connection for e.g.
    console and IRC commands
    """

    def __init__(self, name, server, *rights):
        self.name = name
        self.rights = AttributeSet(rights)
        self.server = server
        self.connection = self
        self.parent = None  # set by call_command

    def get_player(self, name):
        if name is None:
            raise InvalidPlayer()
        return get_player(self.server, name)

    def get_commands(self):
        return self.server.get_commands()

    def get_command(self, name):
        return self.server.get_command(name)
