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

"""
Provides console commands
"""

import sys
import asyncio
from cuwo.common import parse_command
from cuwo.script import ServerScript, ScriptInterface

stdout = sys.__stdout__

def write_stdout(v):
    stdout.write(v.encode(stdout.encoding, 'replace'))

if sys.platform == 'win32':
    import msvcrt

    @asyncio.coroutine
    def async_stdin():
        current = ''
        while True:
            while msvcrt.kbhit():
                c = msvcrt.getwch()
                if c == '\r':  # new line
                    c = '\n'
                    stdout.write(c)
                    current += c
                    break
                elif c in ('\xE0', '\x00'):
                    # ignore special characters
                    msvcrt.getwch()
                elif c == '\x08':  # delete
                    current = self.input[:-1]
                    stdout.write('\x08 \x08')
                else:
                    current += c
                    stdout.write(c)
            yield from asyncio.sleep(0.01)
        return current

else:
    from asyncio.streams import FlowControlMixin 

    reader = None

    @asyncio.coroutine 
    def get_stdin():
        loop = asyncio.get_event_loop() 
        reader = asyncio.StreamReader() 
        reader_protocol = asyncio.StreamReaderProtocol(reader)
        yield from loop.connect_read_pipe(lambda: reader_protocol, sys.stdin)
        return reader 

    @asyncio.coroutine
    def async_stdin():
        global reader
        if reader is None:
            reader = yield from get_stdin() 
        line = yield from reader.readline() 
        return line.decode('utf8')


class ConsoleServer(ServerScript):
    connection_class = None
    io = None

    def on_load(self):
        if not stdout.isatty():
            return
        self.console = ConsoleInput(self.server)
        self.interface = ScriptInterface('Console', server, 'admin', 'console')
        self.task = asyncio.Task(self.loop())

    @asyncio.coroutine
    def loop(self):
        while True:
            line = yield from async_stdin()
            self.handle_line(line)

    def handle_line(self, line):
        if not line.startswith('/'):
            self.server.send_chat(line)
            return
        command, args = parse_command(line[1:])
        if command == 'stop':
            self.server.stop()
            return
        ret = self.server.call_command(self.interface, command, args)
        if not ret:
            return
        print(ret)

    def on_unload(self):
        self.task.cancel()


def get_class():
    return ConsoleServer
