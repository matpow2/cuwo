"""
Encryption utilities for the Cube World data files
Original code by DRayX
"""

import os
import sqlite3

key = [
    4242, 9551, 840, 84800, 9242, 9846, 127, 9, 9483, 394, 123, 4834, 32444,
    24355, 2433, 17, 34234, 42342, 4243, 14, 184934, 1987, 3094, 1901, 89409,
    4813, 37, 143, 3490, 19483, 1343, 432, 84732, 9184, 9612, 1233, 3434, 1839,
    2984, 1993, 2984, 4895, 816583, 13
]


def negate(data):
    for a in data:
        yield ~ord(a) & 0xFF


def decode(data):
    data = bytearray(negate(data))
    for i in reversed(xrange(len(data))):
        j = (i + key[i % len(key)]) % len(data)
        data[i], data[j] = data[j], data[i]
    return data


def encode(data):
    data = bytearray(negate(data))
    for i in xrange(len(data)):
        j = (i + key[i % len(key)]) % len(data)
        data[i], data[j] = data[j], data[i]
    return data


def extract(dbfile, dir):
    try:
        os.makedirs(dir)
    except OSError:
        pass
    conn = sqlite3.connect(dbfile)
    conn.row_factory = sqlite3.Row
    for row in conn.execute('SELECT key, value FROM blobs'):
        with open(os.path.join(dir, row['key']), 'wb') as f:
            f.write(decode(row['value']))


def pack(dbfile, dir):
    files = next(os.walk(dir))[2]
    with sqlite3.connect(dbfile) as conn:
        conn.execute('CREATE TABLE blobs(key TEXT PRIMARY KEY, value BLOB)')
        for name in files:
            with open(os.path.join(dir, name), 'rb') as f:
                data = encode(f.read())
            conn.execute('INSERT INTO blobs(key, value) VALUES(?, ?)',
                         (name, data))


def main():
    extract('map_online_626466.db', 'out2')

if __name__ == '__main__':
    main()
