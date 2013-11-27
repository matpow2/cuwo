import sys
sys.path.append('..')

from cuwo.bytes import ByteReader, ByteWriter
from cuwo.qmo import QubicleFile, QubicleModel
import os


def switch_axes(x, y, z):
    return x, z, y


def convert_qmo(path):
    data = ByteReader(open(path, 'rb').read())

    qmo_file = QubicleFile()
    qmo_model = QubicleModel()
    x_size, y_size, z_size = 256, 256, 256
    qmo_model.x_size = x_size
    qmo_model.y_size = y_size
    qmo_model.z_size = z_size
    qmo_model.x_offset = -x_size / 2
    qmo_model.y_offset = 0
    qmo_model.z_offset = -z_size / 2

    min_z = None
    max_z = None

    for i in xrange(256*256):
        something = data.read_float()
        something2 = data.read_float()
        something3 = data.read_float()
        something4 = data.read_uint32()
        something5 = data.read_uint32()
        size = data.read_uint32()*4
        chunk_data = data.read(size)

        x = i % 256
        y = i / 256

        z = something4

        if min_z is None or max_z is None:
            min_z = z
            max_z = z + len(chunk_data) / 4
        else:
            min_z = min(z, min_z)
            max_z = max(max_z, len(chunk_data) / 4)

        for i in xrange(len(chunk_data) / 4):
            r = ord(chunk_data[i*4])
            g = ord(chunk_data[i*4+1])
            b = ord(chunk_data[i*4+2])
            a = ord(chunk_data[i*4+3])
            if a == 0:
                z += 1
                continue
            qmo_model.blocks[switch_axes(x, y, z)] = (r, g, b)
            z += 1

    qmo_model.y_offset

    qmo_file.models.append(qmo_model)
    writer = ByteWriter()
    qmo_file.write(writer)
    name = os.path.splitext(os.path.basename(path))[0]
    out_path = os.path.join('genqmo', name + '.qmo')
    open(out_path, 'wb').write(writer.get())

    print 'Converted', path

def main():
    for f in os.listdir('genout'):
        path = os.path.join('genout', f)
        convert_qmo(path)

if __name__ == '__main__':
    main()
