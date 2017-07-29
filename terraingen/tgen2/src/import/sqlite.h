/*
    Copyright (c) Mathias Kaerlev 2013-2017.

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
#include <string>
#include <algorithm>

#define MAX_DATABASE 8

const char * translate_path(char *);

class SQLDatabase
{
public:
    sqlite3 * db;
    sqlite3_stmt * statement;
    void * blob_mem;

    SQLDatabase(char * filename)
    : blob_mem(NULL), db(NULL), statement(NULL)
    {
        const char * path = translate_path(filename);
        int ret = sqlite3_open(path, &db);
        if (ret == SQLITE_OK)
            return;
        std::cout << "DB open failed for " << path << ": " << ret << std::endl;
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

    void * column_blob(int32_t column)
    {
        int32_t bytes = column_bytes(column);
        const void * data = sqlite3_column_blob(statement, column);
        blob_mem = heap_alloc(bytes);
        memcpy(blob_mem, data, bytes);
        return blob_mem;
    }

    int32_t finalize()
    {
        if (blob_mem != NULL) {
            heap_dealloc(blob_mem);
            blob_mem = NULL;
        }
        int32_t ret = sqlite3_finalize(statement);
        statement = NULL;
        return ret;
    }

    int32_t close()
    {
        if (blob_mem != NULL)
            heap_dealloc(blob_mem);
        return sqlite3_close(db);
    }
};

static SQLDatabase* databases[MAX_DATABASE] = {NULL};

inline SQLDatabase * get_db(uint32_t v)
{
    return databases[v];
}

// sqlite3_prepare
// table: SQLITE_TABLE+4*72
int32_t sub_469210(uint32_t db, char * sql, uint32_t num, uint32_t * stm,
                   uint32_t tail)
{
    // std::cout << "sqlite3_prepare: " << sql << std::endl;
    *stm = db;
    // use the database id for statement
    return get_db(db)->prepare(sql);
}

// sqlite3_bind_text
// table: SQLITE_TABLE+4*10
int32_t sub_4698F0(uint32_t stm, uint32_t index, char * value,
                   int32_t bytes, uint32_t cb)
{
    // std::cout << "sqlite3_bind_text: " << value << std::endl;
    return get_db(stm)->bind_text(index, value);
}

// sqlite3_step
// table: SQLITE_TABLE+4*94
int32_t sub_46A090(uint32_t stm)
{
    // std::cout << "sqlite3_step" << std::endl;
    return get_db(stm)->step();
}

// sqlite3_finalize
// table: SQLITE_TABLE+4*57
int32_t sub_46AE00(uint32_t stm)
{
    // std::cout << "sqlite3_finalize" << std::endl;
    return get_db(stm)->finalize();
}

// sqlite3_column_bytes
// table: SQLITE_TABLE+4*20
int32_t sub_46A3A0(uint32_t stm, int32_t col)
{
    return get_db(stm)->column_bytes(col);
    // std::cout << "sqlite3_column_bytes" << std::endl;
}

// sqlite3_column_blob
// table: SQLITE_TABLE+4*19
void * sub_46A320(uint32_t stm, int32_t col)
{
    return get_db(stm)->column_blob(col);
    // std::cout << "sqlite3_column_blob" << std::endl;
}

// sqlite3_close
// table: SQLITE_TABLE+4*16
int32_t sub_4633C0(uint32_t db)
{
    // std::cout << "sqlite3_close" << std::endl;
    SQLDatabase * p = get_db(db);
    int32_t ret = p->close();
    delete p;
    databases[db] = NULL;
    return ret;
}

// sqlite3_bind_blob
// table: SQLITE_TABLE+4*2
int32_t sub_469530(uint32_t stm, uint32_t index, char * value, uint32_t bytes,
                   uint32_t cb)
{
    // std::cout << "sqlite3_bind_blob" << std::endl;
    return get_db(stm)->bind_blob(index, value, bytes);
}

// sqlite3_open
// table: SQLITE_TABLE+4*70
int32_t sub_468330(char * filename, uint32_t * db)
{
    // std::cout << "sqlite3_open: " << filename << std::endl;
    // db -> sqlite3 **ppDb

    int i;
    for (i = 0; i < MAX_DATABASE; i++) {
        if (databases[i] != NULL)
            continue;
        break;
    }

    databases[i] = new SQLDatabase(filename);
    *db = i;

    return SQLITE_OK;
}

// sqlite3_exec
// table: SQLITE_TABLE+4*55
int32_t sub_463500(uint32_t db, char * sql, uint32_t callback, uint32_t arg,
                   uint32_t err)
{
    // std::cout << "sqlite3_exec: " << sql << std::endl;
    return get_db(db)->exec(sql);
}

// sqlite3_thread_cleanup
// table: SQLITE_TABLE+4*96
void sub_46B620()
{
    // std::cout << "sqlite_thread_cleanup" << std::endl;
}

#endif // TERRAINGEN_SQLITE_H
