#ifndef TGEN_MSVCSTRING_H
#define TGEN_MSVCSTRING_H

#include <string>

#define BUF_SIZE_CHAR 16

struct basic_string_char
{
    union {
        uint8_t buf[BUF_SIZE_CHAR];
        uint32_t ptr;
    };
    uint32_t size;
    uint32_t res; // capacity

    void reset()
    {
        size = 0;
        res = 15;
    }

    char * get()
    {
        if (size < BUF_SIZE_CHAR)
            return (char*)&buf;
        return (char*)ptr;
    }

    std::string str()
    {
        return std::string(get(), size);
    }

    void str(std::string & str)
    {
        str.assign(get(), size);
    }
};

struct basic_string_wchar
{
    union {
        uint8_t buf[BUF_SIZE_CHAR];
        uint32_t ptr;
    };
    uint32_t size;
    uint32_t res; // capacity

    void reset()
    {
        size = 0;
        res = 15;
    }

    char * get()
    {
        if (size*2 < BUF_SIZE_CHAR)
            return (char*)&buf;
        return (char*)ptr;
    }

    std::string str()
    {
        return std::string(get(), size*2);
    }

    void str(std::string & str)
    {
        str.assign(get(), size*2);
    }
};

#endif // TGEN_MSVCSTRING_H
