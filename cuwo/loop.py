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

import asyncio


class LoopingCall:
    handle = None

    def __init__(self, func, *arg, loop=None, **kw):
        self.func = func
        self.arg = arg
        self.kw = kw
        self.loop = loop or asyncio.get_event_loop()

    def start(self, interval, now=False):
        self.stop()
        self.schedule(interval, now)

    def stop(self):
        if not self.handle:
            return
        self.handle.cancel()
        self.handle = None

    def schedule(self, interval, now):
        self.dt = interval
        self.handle = self.loop.call_later(interval, self.schedule,
                                           interval, True)
        if now:
            self.func(*self.arg, **self.kw)
