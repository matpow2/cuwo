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

import unittest

import sys
import os
sys.path.append('.')
from cuwo import tgen
from cuwo.bytes import ByteReader
from cuwo.static import StaticEntityHeader
import zlib
import subprocess


class TerrainGeneratorTests(unittest.TestCase):
    def setUp(self):
        print('Initializing tgen')
        tgen.initialize(26879, './data/')
        print('Done')

    def test_static_entities(self):
        with open('./tests/tgen_static.dat', 'rb') as fp:
            data = zlib.decompress(fp.read())

        reader = ByteReader(data)
        source = []
        while reader.get_left() > 0:
            entity = StaticEntityHeader()
            entity.read(reader)
            source.append(entity)

        chunk = tgen.generate(32803, 32803)
        # chunk = tgen.generate(32803, 32803)
        # tgen.dump_mem('dump.bin')

        self.assertEqual(len(chunk.static_entities), len(source))

        for index, entity in enumerate(chunk.static_entities):
            header1 = entity.header
            header2 = source[index]
            self.assertEqual(header1.entity_type, header2.entity_type)
            self.assertEqual(header1.pos, header2.pos)
            self.assertEqual(header1.orientation, header2.orientation)
            self.assertEqual(header1.size, header2.size)
            self.assertEqual(header1.closed, header2.closed)
            self.assertEqual(header1.time_offset, header2.time_offset)
            self.assertEqual(header1.something8, header2.something8)
            self.assertEqual(header1.user_id, header2.user_id)


        for index, entity in enumerate(chunk.items):
            print(entity)

        events = [
            ('generate', (1007, 4974)),
            ('generate', (1007, 4973)),
            ('generate', (1007, 4972)),
            ('generate', (1007, 4971)),
            ('destroy', (1007, 4973)),
            ('generate', (1007, 4970)), 
            ('destroy', (1007, 4972)),
            ('generate', (1007, 4969))
        ]

        chunks = {}

        for (event, chunk) in events:
            if event == 'generate':
                chunks[chunk] = tgen.generate(*chunk)
            elif event == 'destroy':
                chunks[chunk].destroy()

if __name__ == '__main__':
    unittest.main()