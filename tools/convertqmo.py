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

import sys
sys.path.append('.')

from cuwo.bytes import ByteReader, ByteWriter
from cuwo.qmo import QubicleFile, QubicleModel
from cuwo.cub import CubModel
import glob
import os

def switch_axes(x, y, z):
    return x, z, y

def to_qmo(in_file, out_file):
    cub = CubModel(ByteReader(fp = open(in_file, 'rb')))
    qmo_file = QubicleFile()
    qmo_model = QubicleModel()
    x_size,  y_size, z_size = switch_axes(cub.x_size, cub.y_size, cub.z_size)
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
    qmo_file.write(ByteWriter(fp = open(out_file, 'wb')))

def main():
    print 'QMO/CUB converter'
    for item in glob.glob('./src/*.cub'):
        basename = os.path.basename(item)
        to_qmo(item, './out/' + basename)

if __name__ == '__main__':
    main()