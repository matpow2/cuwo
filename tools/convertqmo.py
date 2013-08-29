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

import os
import sys
import argparse
cmd_folder = os.path.realpath(os.path.abspath('.'))
if cmd_folder not in sys.path:
    sys.path.insert(0, cmd_folder)

from cuwo.bytes import ByteReader, ByteWriter
from cuwo.qmo import QubicleFile, QubicleModel
from cuwo.cub import CubModel
import os


def switch_axes(x, y, z):
    return x, z, y


def to_qmo(in_file, out_file):
    cub = CubModel(ByteReader(open(in_file, 'rb').read()))
    qmo_file = QubicleFile()
    qmo_model = QubicleModel()
    x_size, y_size, z_size = switch_axes(cub.x_size, cub.y_size, cub.z_size)
    qmo_model.x_size = x_size
    qmo_model.y_size = y_size
    qmo_model.z_size = z_size
    qmo_model.x_offset = -x_size / 2
    qmo_model.y_offset = 0
    qmo_model.z_offset = -z_size / 2
    for k, v in cub.blocks.iteritems():
        x, y, z = k
        x2, y2, z2 = switch_axes(x, y, z)
        qmo_model.blocks[x2, y2, z2] = v
    qmo_file.models.append(qmo_model)
    writer = ByteWriter()
    qmo_file.write(writer)
    with open(out_file, 'wb') as fp:
        fp.write(writer.get())


def to_cub(in_file, out_file):
    qmo_file = QubicleFile(ByteReader(open(in_file, 'rb').read()))
    qmo_model = qmo_file.models[0]
    cub = CubModel()
    x_size, y_size, z_size = switch_axes(qmo_model.x_size,
                                         qmo_model.y_size,
                                         qmo_model.z_size)
    cub.x_size = x_size
    cub.y_size = y_size
    cub.z_size = z_size
    for k, v in qmo_model.blocks.iteritems():
        x, y, z = k
        x2, y2, z2 = switch_axes(x, y, z)
        cub.blocks[x2, y2, z2] = v
    writer = ByteWriter()
    cub.write(writer)
    with open(out_file, 'wb') as fp:
        fp.write(writer.get())


def main():
    parser = argparse.ArgumentParser(
        description='Convert between cub and qmo files')
    parser.add_argument('files', metavar='FILE', nargs='+',
                        help='path to file to convert')

    for path in parser.parse_args().files:
        print "Converting %r" % path
        filename, ext = os.path.splitext(path)
        if ext == '.cub':
            to_qmo(path, filename + '.qmo')
        else:
            to_cub(path, filename + '.cub')

if __name__ == '__main__':
    main()
