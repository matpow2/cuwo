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
World manager
"""

from cuwo import tgen
from twisted.internet import reactor, defer
from Queue import Queue


class GenerateData(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.d = defer.Deferred()


class World(object):
    running = True

    def __init__(self, seed):
        self.gen_queue = Queue()
        self.cache = {}
        reactor.callInThread(self.run_gen, seed)
        reactor.addSystemEventTrigger('before', 'shutdown', self.on_shutdown)

    def on_shutdown(self):
        self.gen_queue.put(None)

    def get_chunk(self, x, y):
        try:
            return defer.succeed(self.cache[(x, y)])
        except KeyError:
            pass
        data = GenerateData(x, y)
        self.gen_queue.put(data, False)
        return data.d

    def run_gen(self, seed):
        tgen.initialize(seed)
        while True:
            data = self.gen_queue.get()
            if data is None:
                break
            key = (data.x, data.y)
            res = self.cache.get(key, None)
            if res is None:
                res = tgen.generate(data.x, data.y)
                self.cache[key] = res
            reactor.callFromThread(data.d.callback, res)
