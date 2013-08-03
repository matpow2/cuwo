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
Wrappers for gevent and misc. functionality like looping calls
"""

import time
import gevent


seconds = time.time
sleep = gevent.sleep
call_later = gevent.spawn_later


class LoopingCall(object):
    closed = False

    def __init__(self, f, *args, **kw):
        self.func = f
        self.args = args
        self.kw = kw

    def start(self, interval):
        self.closed = False
        self.interval = interval
        gevent.spawn(self.loop)

    def loop(self):
        while True:
            start = seconds()
            self.func(*self.args, **self.kw)
            current = seconds()
            gevent.sleep(max(0, current + self.interval - start))

    def stop(self):
        self.closed = True


def call_later(interval, f, *args, **kw):
    return gevent.spawn_later(interval, f, *args, **kw)


def start_loop(interval, f, *arg, **kw):
    call = LoopingCall(f, *arg, **kw)
    call.start(interval)
    return call
