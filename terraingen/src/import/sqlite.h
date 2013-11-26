/*
    Copyright (c) Mathias Kaerlev 2013.

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

#ifndef TERRAINGEN_SQLITE_H
#define TERRAINGEN_SQLITE_H

#include "sqlite3.h"

#define MAX_DATABASE 8

class SQLDatabase
{
public:
    sqlite3 * db;
    sqlite3_stmt * statement;
    uint32_t blob_mem;

    SQLDatabase(char * filename)
    : blob_mem(0)
    {
        int ret = sqlite3_open(filename, &db);
        // std::cout << "Open: " << ret << std::endl;
    }

    int32_t exec(char * value)
    {
        return sqlite3_exec(db, value, NULL, NULL, NULL);
    }

    int32_t prepare(char * value)
    {
        return sqlite3_prepare(db, value, -1, &statement, 0);
    }

    int32_t bind_text(uint32_t index, char * value)
    {
        return sqlite3_bind_text(statement, index, value, -1, NULL);
    }

    int32_t bind_blob(uint32_t index, char * value, uint32_t bytes)
    {
        return sqlite3_bind_blob(statement, index, value, bytes, NULL);
    }

    int32_t step()
    {
        return sqlite3_step(statement);
    }

    int32_t column_bytes(int32_t column)
    {
        return sqlite3_column_bytes(statement, column);
    }

    uint32_t column_blob(int32_t column)
    {
        int32_t bytes = column_bytes(column);
        const void * data = sqlite3_column_blob(statement, column);
        blob_mem = mem.heap_alloc(bytes);
        memcpy(mem.translate(blob_mem), data, bytes);
        return blob_mem;
    }

    int32_t finalize()
    {
        if (blob_mem != 0) {
            mem.heap_dealloc(blob_mem);
            blob_mem = 0;
        }
        int32_t ret = sqlite3_finalize(statement);
        statement = NULL;
        return ret;
    }

    int32_t close()
    {
        if (blob_mem != 0)
            mem.heap_dealloc(blob_mem);
        return sqlite3_close(db);
    }
};

static SQLDatabase* databases[MAX_DATABASE] = {NULL};

inline SQLDatabase * get_db(uint32_t v)
{
    return databases[v];
}

// sqlite3_prepare
void sub_469210()
{
    pop_ret();
    uint32_t db = cpu.get_dword(0);
    char * sql = mem.translate(cpu.get_dword(4));
    uint32_t num = cpu.get_dword(8);
    uint32_t stm = cpu.get_dword(12);
    uint32_t tail = cpu.get_dword(16);
    // use the database id for statement
    mem.write_dword(stm, db);
    set_ret(get_db(db)->prepare(sql));
    // std::cout << "sqlite3_prepare: " << sql << std::endl;
}

// sqlite3_bind_text
void sub_4698F0()
{
    pop_ret();
    uint32_t stm = cpu.get_dword(0);
    uint32_t index = cpu.get_dword(4);
    char * value = mem.translate(cpu.get_dword(8));
    int32_t bytes = (int32_t)cpu.get_dword(12);
    uint32_t cb = cpu.get_dword(16);
    set_ret(get_db(stm)->bind_text(index, value));
    // std::cout << "sqlite3_bind_text: " << value << std::endl;
}

// sqlite3_step
void sub_46A090()
{
    pop_ret();
    uint32_t stm = cpu.get_dword(0);
    set_ret(get_db(stm)->step());
    // std::cout << "sqlite3_step" << std::endl;
}

// sqlite3_finalize
void sub_46AE00()
{
    pop_ret();
    uint32_t stm = cpu.get_dword(0);
    set_ret(get_db(stm)->finalize());
    // std::cout << "sqlite3_finalize" << std::endl;
}

// sqlite3_column_bytes
void sub_46A3A0()
{
    pop_ret();
    uint32_t stm = cpu.get_dword(0);
    int32_t col = (int32_t)cpu.get_dword(4);
    set_ret(get_db(stm)->column_bytes(col));
    // std::cout << "sqlite3_column_bytes" << std::endl;
}

// sqlite3_column_blob
void sub_46A320()
{
    pop_ret();
    uint32_t stm = cpu.get_dword(0);
    int32_t col = (int32_t)cpu.get_dword(4);
    set_ret(get_db(stm)->column_blob(col));
    // std::cout << "sqlite3_column_blob" << std::endl;
}

// sqlite3_close
void sub_4633C0()
{
    pop_ret();
    uint32_t db = cpu.get_dword(0);
    SQLDatabase * p = get_db(db);
    set_ret(p->close());
    delete p;
    databases[db] = NULL;
    // std::cout << "sqlite3_close" << std::endl;
}

// sqlite3_bind_blob
void sub_469530()
{
    pop_ret();
    uint32_t stm = cpu.get_dword(0);
    uint32_t index = cpu.get_dword(4);
    char * value = mem.translate(cpu.get_dword(8));
    uint32_t bytes = cpu.get_dword(12);
    uint32_t cb = cpu.get_dword(16);
    set_ret(get_db(stm)->bind_blob(index, value, bytes));
    // std::cout << "sqlite3_bind_blob" << std::endl;
}

// sqlite3_open
void sub_468330()
{
    pop_ret();
    char * filename = mem.translate(cpu.get_dword(0));
    uint32_t db = cpu.get_dword(4); // sqlite3 **ppDb

    int i;
    for (i = 0; i < MAX_DATABASE; i++) {
        if (databases[i] != NULL)
            continue;
        break;
    }

    databases[i] = new SQLDatabase(filename);
    mem.write_dword(db, i);

    set_ret(SQLITE_OK);
    // std::cout << "sqlite3_open: " << filename << std::endl;
}

// sqlite3_exec
void sub_463500()
{
    pop_ret();
    uint32_t db = cpu.get_dword(0);
    char * sql = mem.translate(cpu.get_dword(4));
    uint32_t callback = cpu.get_dword(8);
    uint32_t arg = cpu.get_dword(12);
    uint32_t err = cpu.get_dword(16);
    set_ret(get_db(db)->exec(sql));
    // std::cout << "sqlite3_exec: " << sql << std::endl;
}

// sqlite3_thread_cleanup
void sub_46B620()
{
    pop_ret();
    // std::cout << "sqlite_thread_cleanup" << std::endl;
}

#endif // TERRAINGEN_SQLITE_H
