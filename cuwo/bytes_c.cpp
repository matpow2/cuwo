/*
    Copyright (c) Mathias Kaerlev 2013-2014.

    This file is part of cuwo.

    cuwo is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cuwo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cuwo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <sstream>
#include <string>
#include "Python.h"
using namespace std;

#ifdef _MSC_VER
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif


/*
read methods
*/

inline char read_int8(char * data)
{
    return data[0];
}

inline unsigned char read_uint8(char * data)
{
    return (unsigned char)read_int8(data);
}

inline short read_int16(char * data)
{
    unsigned char * bytes = (unsigned char*)data;
    return bytes[0] | (bytes[1] << 8);
}

inline unsigned short read_uint16(char * data)
{
    return (unsigned short)read_int16(data);
}

inline int read_int32(char * data)
{
    unsigned char * bytes = (unsigned char*)data;
    return bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);
}

inline unsigned int read_uint32(char * data)
{
    return (unsigned int)read_int32(data);
}

inline int64_t read_int64(char * data)
{
    unsigned char * bytes = (unsigned char*)data;
    int64_t value = 0;
    value |= (int64_t)bytes[0];
    value |= (int64_t)bytes[1] << 8;
    value |= (int64_t)bytes[2] << 16;
    value |= (int64_t)bytes[3] << 24;
    value |= (int64_t)bytes[4] << 32;
    value |= (int64_t)bytes[5] << 40;
    value |= (int64_t)bytes[6] << 48;
    value |= (int64_t)bytes[7] << 56;
    return value;
}

inline uint64_t read_uint64(char * data)
{
    return (uint64_t)read_int64(data);
}

inline double read_float(char * data)
{
    return _PyFloat_Unpack4((const unsigned char*)data, true);
}

inline double read_double(char * data)
{
    return _PyFloat_Unpack8((const unsigned char*)data, true);
}

/*
write methods
*/

inline void * create_write_stream()
{
    ostringstream * ss = new ostringstream(ostringstream::out |
                                           ostringstream::binary);
    return (void*)ss;
}

inline void delete_write_stream(void * ss)
{
    delete (ostringstream*)ss;
}

inline void write_pad(void * stream, size_t size)
{
    ostringstream * ss = (ostringstream*)stream;
    for (unsigned int i = 0; i < size; i++)
        ss->put(0);
}

inline void write_int8(void * stream, char value)
{
    ostringstream * ss = (ostringstream*)stream;
    ss->put(value);
}

inline void write_uint8(void * stream, unsigned char value)
{
    ostringstream * ss = (ostringstream*)stream;
    ss->put((char)value);
}

inline void write_int16(void * stream, short value)
{
    ostringstream * ss = (ostringstream*)stream;
    ss->put((char)value);
    ss->put((char)(value >> 8));
}

inline void write_uint16(void * stream, unsigned short value)
{
    write_int16(stream, (short)value);
}

inline void write_int32(void * stream, int value)
{
    ostringstream * ss = (ostringstream*)stream;
    ss->put((char)value);
    ss->put((char)(value >> 8));
    ss->put((char)(value >> 16));
    ss->put((char)(value >> 24));
}

inline void write_uint32(void * stream, unsigned int value)
{
    write_int32(stream, (int)value);
}

inline void write_int64(void * stream, int64_t value)
{
    ostringstream * ss = (ostringstream*)stream;
    ss->put((char)value);
    ss->put((char)(value >> 8));
    ss->put((char)(value >> 16));
    ss->put((char)(value >> 24));
    ss->put((char)(value >> 32));
    ss->put((char)(value >> 40));
    ss->put((char)(value >> 48));
    ss->put((char)(value >> 56));
}

inline void write_uint64(void * stream, uint64_t value)
{
    write_int64(stream, (int64_t)value);
}

inline void write_float(void * stream, double value)
{
    ostringstream * ss = (ostringstream*)stream;
    char out[4];
    _PyFloat_Pack4(value, (unsigned char *)&out, true);
    ss->write(out, 4);
}

inline void write_double(void * stream, double value)
{
    ostringstream * ss = (ostringstream*)stream;
    char out[8];
    _PyFloat_Pack8(value, (unsigned char *)&out, true);
    ss->write(out, 8);
}

inline void write(void * stream, char * data, size_t size)
{
    ostringstream * ss = (ostringstream*)stream;
    ss->write(data, size);
}

inline size_t get_write_pos(void * stream)
{
    ostringstream * ss = (ostringstream*)stream;
    streampos pos = ss->tellp();
    if (pos == (streampos)-1)
        return 0;
    return pos;
}

inline PyObject * get_stream_data(void * stream)
{
    ostringstream * ss = (ostringstream*)stream;
    const string tmp = ss->str();
    return PyString_FromStringAndSize(tmp.c_str(), tmp.length());
}
