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
Since the default asyncio eventloop uses a very imprecise timer
on Windows, we need to reimplement it here.

Hopefully this will be fixed in a future version of asyncio.

Relevant discussion:
https://groups.google.com/forum/?fromgroups#!topic/python-tulip/yUFm29WPt88
"""

from ctypes import windll
timeGetTime = windll.winmm.timeGetTime
timeBeginPeriod = windll.winmm.timeBeginPeriod
timeEndPeriod = windll.winmm.timeEndPeriod

from asyncio import windows_events


def fix_event_loop(klass):
    class EventLoop(klass):
        def __init__(self):
            super().__init__()
            # 10 ms resolution
            self._clock_resolution = 10 * 1e-3
            self._last_time = 0
            self._n_overflow = 0

        def run_forever(self):
            period = int(self._clock_resolution * 1e3)
            timeBeginPeriod(period)
            super().run_forever()
            # restore timer resolution
            timeEndPeriod(period)

        def time(self):
            # lifted from timemodule.c (pymonotonic)
            t = timeGetTime()
            if t < self._last_time:
                self._n_overflow += 0x100000000
            self._last_time = t
            return (t + self._n_overflow) * 1e-3

    return EventLoop

ProactorEventLoop = fix_event_loop(windows_events.ProactorEventLoop)
SelectorEventLoop = fix_event_loop(windows_events.SelectorEventLoop)
