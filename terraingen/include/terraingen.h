#ifndef TERRAINGEN_API
#define TERRAINGEN_API

struct ChunkEntry
{
    unsigned char r, g, b, a;
};

struct ChunkXY
{
    int a, b;
    unsigned int size;
    ChunkEntry * items;
};

struct ChunkData
{
    int x, y;
    ChunkXY items[256*256];
    size_t item_size;
    char * item_data;
};

void tgen_init();
void tgen_set_seed(unsigned int seed);
ChunkData * tgen_generate_chunk(unsigned int x, unsigned int y);
void tgen_destroy_chunk(ChunkData * data);
void tgen_dump_mem(const char * filename);
void tgen_set_path(const char * dir);
unsigned int tgen_generate_debug_chunk(const char * filename,
                                       unsigned int x, unsigned int y);

#endif // TERRAINGEN_API
