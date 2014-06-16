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

import sys
sys.path.append('.')
from cuwo import tgen
from cuwo.bytes import ByteWriter
from cuwo.qmo import QubicleFile, QubicleModel
import argparse


def switch_axes(x, y, z):
    return x, z, y


def convert_qmo(data, path):
    qmo_file = QubicleFile()
    qmo_model = QubicleModel()
    x_size, y_size, z_size = 256, 256, 256
    qmo_model.x_size = x_size
    qmo_model.y_size = y_size
    qmo_model.z_size = z_size
    qmo_model.x_offset = -x_size / 2
    qmo_model.y_offset = 0
    qmo_model.z_offset = -z_size / 2

    blocks = data.get_dict()

    min_z = max_z = None
    for pos in blocks.keys():
        x, y, z = pos
        if min_z is None:
            min_z = max_z = z
        min_z = min(min_z, z)
        max_z = max(max_z, z)

    qmo_model.y_size = max_z - min_z + 1

    for pos, color in blocks.items():
        x, y, z = switch_axes(*pos)
        y -= min_z
        qmo_model.blocks[(x, y, z)] = color

    qmo_file.models.append(qmo_model)
    writer = ByteWriter()
    qmo_file.write(writer)
    open(path, 'wb').write(writer.get())


def convert_pos(x, y, f):
    print('Generating', x, y)
    data = tgen.generate(x, y)
    for entity in data.static_entities:
        if not entity.items:
            continue
        print('Has items')
    import code
    code.interact(local=locals())
    print(data.static_entities)
    # print('Converting...')
    # convert_qmo(data, f)


def coords(s):
    try:
        x, y = list(map(int, s.split(',')))
        return x, y
    except ValueError:
        raise argparse.ArgumentTypeError("Coordinates must be x,y")


def main():
    parser = argparse.ArgumentParser(description='Generates chunks using tgen')
    parser.add_argument('seed', help='input seed', type=int)
    parser.add_argument('coords', help='input coordinates',
                        type=coords, nargs='+')

    args = parser.parse_args()

    print('Initializing...')
    val = './data/'
    tgen.initialize(args.seed, val)
    for coord in args.coords:
        x, y = coord
        f = '%s_%s.qmo' % (x, y)
        convert_pos(x, y, f)
    print('Done')


if __name__ == '__main__':
    main()