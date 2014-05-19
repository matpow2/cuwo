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

import signal
from ctypes import windll
from asyncio import windows_events

timeGetTime = windll.winmm.timeGetTime
timeBeginPeriod = windll.winmm.timeBeginPeriod
timeEndPeriod = windll.winmm.timeEndPeriod
TIMERR_NOERROR = 0


def fix_event_loop(klass):
    class EventLoop(klass):
        def __init__(self):
            super().__init__()

            # Ensure that the scheduler never tries to fire a call in the
            # future, so use the highest timer resolution of 1ms as the clock
            # resolution used for scheduling
            self._clock_resolution = 1 * 1e-3
            self._use_default_clock = True
            self._time_period = None
            self._last_time = 0
            self._time_overflow = 0

        def _set_time_period(self, period):
            self._restore_time_period()
            self._time_period = period
            return timeBeginPeriod(period) == TIMERR_NOERROR

        def _restore_time_period(self):
            if self._time_period is None:
                return
            timeEndPeriod(self._time_period)
            self._time_period = None

        def set_clock_resolution(self, clock_resolution):
            """Sets the internal clock resolution.

            Returns False if the clock resolution is not supported.
            """
            if not self._use_default_clock:
                return False
            period = max(1, int(clock_resolution * 1e3))
            return self._set_time_period(period)

        def set_clock(self, time_func, clock_resolution):
            """Sets the internal clock implementation.

            Returns False if the event loop does not support changes to its
            clock.
            """
            self.time = time_func
            self._clock_resolution = clock_resolution
            self._use_default_clock = False
            self._restore_time_period()
            return True

        def close(self):
            self._restore_time_period()
            super().close()

        def add_signal_handler(self, sig, callback, *args):
            def signal_handler(signal, frame):
                self.call_soon_threadsafe(callback, *args)
            signal.signal(sig, signal_handler)

        def time(self):
            # lifted from timemodule.c (pymonotonic)
            t = timeGetTime()
            if t < self._last_time:
                self._time_overflow += 0x100000000
            self._last_time = t
            return (t + self._time_overflow) * 1e-3

    return EventLoop

ProactorEventLoop = fix_event_loop(windows_events.ProactorEventLoop)
SelectorEventLoop = fix_event_loop(windows_events.SelectorEventLoop)

# Use SelectorEventLoop by default
WindowsEventLoop = SelectorEventLoop
