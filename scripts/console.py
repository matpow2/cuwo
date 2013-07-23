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

"""
Provides console commands
"""

import sys
from twisted.protocols.basic import LineReceiver
from twisted.internet.task import LoopingCall
from cuwo.common import parse_command
from cuwo.script import ServerScript, ScriptInterface

stdout = sys.__stdout__

if sys.platform == 'win32':
    # StandardIO on Windows does not work, so we create a silly replacement
    import msvcrt

    class StandardIO(object):
        disconnecting = False
        interval = 0.01
        input = u''

        def __init__(self, protocol):
            self.protocol = protocol
            protocol.makeConnection(self)
            self.input_loop = LoopingCall(self.get_input)
            self.input_loop.start(0.01)

        def loseConnection(self):
            self.input_loop.stop()

        def get_input(self):
            while msvcrt.kbhit():
                c = msvcrt.getwch()
                if c == u'\r':  # new line
                    c = u'\n'
                    stdout.write(c)
                    self.input += c
                    self.protocol.dataReceived(self.input)
                    self.input = ''
                elif c in (u'\xE0', u'\x00'):
                    # ignore special characters
                    msvcrt.getwch()
                elif c == u'\x08':  # delete
                    self.input = self.input[:-1]
                    stdout.write('\x08 \x08')
                else:
                    self.input += c
                    stdout.write(c)

        def write(self, data):
            stdout.write(data)

        def writeSequence(self, seq):
            stdout.write(''.join(seq))
else:
    from twisted.internet.stdio import StandardIO


class ConsoleInput(LineReceiver):
    delimiter = '\n'

    def __init__(self, server):
        self.server = server
        self.interface = ScriptInterface(server, 'admin', 'console')

    def lineReceived(self, line):
        if line.startswith('/'):
            command, args = parse_command(line[1:])
            if command == 'stop':
                self.server.stop()
                return
            ret = self.server.call_command(self.interface, command, args)
            if not ret:
                return
            self.sendLine(ret)
        else:
            self.server.send_chat(line)


class ConsoleServer(ServerScript):
    connection_class = None

    def on_load(self):
        self.console = ConsoleInput(self.server)
        self.io = StandardIO(self.console)

    def on_unload(self):
        self.io.loseConnection()


def get_class():
    return ConsoleServer
