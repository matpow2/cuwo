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

from cuwo.types import AttributeSet, AttributeDict
import collections
import sys
import inspect


class InvalidPlayer(Exception):
    pass


class InsufficientRights(Exception):
    pass


def get_command_list(playerscript):
    script_list = playerscript.server.scripts.scripts
    rights = playerscript.connection.rights
    available_commands = []
    for script in script_list.itervalues():
        if script.commands is None:
            continue
        for name, command in script.commands.iteritems():
            user_types = getattr(command, 'user_types', None)
            if (user_types is None
                    or not rights.isdisjoint(user_types)):
                available_commands.append(name)
    return available_commands


def get_command_func(playerscript, func_name):
    script_list = playerscript.server.scripts.scripts
    for script in script_list.itervalues():
        if script.commands is None:
            continue
        if func_name in script.commands:
            return script.commands[func_name]
    return None


def resolve_command_func(func):
    new_func = getattr(func, 'func', None)
    if not new_func is None:
        func = new_func
    return func


def get_min_command_arguments(func):
    func_info = inspect.getargspec(func)
    min_args = len(func_info.args) - 1
    if not func_info.defaults is None:
        min_args -= len(func_info.defaults)
    return min_args


def get_command_syntax(func):
    func_info = inspect.getargspec(func)
    syntax = 'Syntax: /' + func.func_name
    for i in xrange(1, len(func_info.args)):
        argument = func_info.args[i]
        if not func_info.defaults is None:
            defaults_start = len(func_info.args) - len(func_info.defaults)
            defaults_index = i - defaults_start
            if defaults_index >= 0:
                default = func_info.defaults[defaults_index]
                if default is None:
                    syntax += ' [%s]' % argument
                else:
                    syntax += ' [%s=%s]' % (argument, default)
                continue
        syntax += ' %s' % argument
    return syntax


def get_command_help(func):
    information = func.__doc__
    syntax = get_command_syntax(func)

    if information is None:
        return syntax
    return "%s\n%s" % (information, syntax)


def get_player(server, value):
    ret = None
    players = server.players
    try:
        if value.startswith('#'):
            value = int(value[1:])
            ret = players[value]
        else:
            try:
                ret = players[value]
            except KeyError:
                value = value.lower()
                for player in players.values():
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


def restrict(*user_types):
    """
    Restricts the command to certain user types
    """
    def dec(func):
        def new_func(script, *arg, **kw):
            if script.connection.rights.isdisjoint(user_types):
                raise InsufficientRights()
            return func(script, *arg, **kw)
        new_func.func = func
        new_func.__module__ = func.__module__
        new_func.func_name = func.func_name
        new_func.user_types = user_types
        return new_func
    return dec


# decorator to restrict the use of commands to administrators only
admin = restrict('admin')


class ScriptManager(object):
    """
    Manages scripts for either a server or connection
    """
    def __init__(self):
        self.scripts = collections.OrderedDict()
        self.cached_calls = {}

    def __getattr__(self, name):
        return self.scripts[name]

    def add(self, script):
        self.scripts[script.script_name] = script
        self.cached_calls.clear()

    def remove(self, script):
        del self.scripts[script.script_name]
        self.cached_calls.clear()

    def unload(self):
        for script in self.scripts.values():
            script.unload()

    def call(self, event_name, **kw):
        try:
            handlers = self.cached_calls[event_name]
        except KeyError:
            handlers = []
            for script in self.scripts.values():
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
            self.on_existing_connection(connection)

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
        f = self.commands.get(command.lower(), None)
        if not f:
            return
        user.parent = self  # for ScriptInterface

        resolved_func = resolve_command_func(f)
        min_args = get_min_command_arguments(resolved_func)
        if len(args) < min_args:
            return get_command_syntax(resolved_func)

        try:
            ret = f(user, *args) or ''
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

    def __init__(self, server, *rights):
        self.rights = AttributeSet(rights)
        self.server = server
        self.connection = self
        self.parent = None  # set by call_command

    def get_player(self, name):
        return get_player(self.server, name)


# decorators for commands
def command(func, klass=None, level=None):
    if klass is None:
        klass = sys.modules[func.__module__].get_class()
    if klass.commands is None:
        klass.commands = {}
    func.level = level
    klass.commands[func.func_name] = func
    return func
