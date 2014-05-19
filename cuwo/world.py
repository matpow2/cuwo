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

import os
from queue import Queue
import asyncio
from cuwo import tgen


class GenerateData:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.f = asyncio.Future()


class World:
    running = True
    data_path = './data/'

    def __init__(self, loop, seed):
        for name in ('data1.db', 'data4.db'):
            path = os.path.join(self.data_path, name)
            if os.path.isfile(path):
                continue
            path = os.path.abspath(path)
            raise FileNotFoundError('Missing asset file %r' % path)

        self.loop = loop
        self.gen_queue = Queue()
        self.cache = {}
        loop.run_in_executor(None, self.run_gen, seed)

    def stop(self):
        self.gen_queue.put(None)

    def get_chunk(self, x, y):
        try:
            chunk = self.cache[(x, y)]
            f = asyncio.Future()
            f.set_result(chunk)
            return f
        except KeyError:
            pass
        data = GenerateData(x, y)
        self.gen_queue.put(data, False)
        return data.f

    def run_gen(self, seed):
        tgen.initialize(seed, self.data_path)
        while True:
            data = self.gen_queue.get()
            if data is None:
                break
            key = (data.x, data.y)
            res = self.cache.get(key, None)
            if res is None:
                res = tgen.generate(data.x, data.y)
                self.cache[key] = res
            self.loop.call_soon_threadsafe(data.f.set_result, res)
