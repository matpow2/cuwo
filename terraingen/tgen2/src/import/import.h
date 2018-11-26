#include <unordered_map>
#include <array>
#include <vector>
#include "import/base.h"
#include "import/sqlite.h"
#include "import/ios.h"
#include <stdint.h>

struct Import
{
#ifdef IS_X64
    unsigned char * asm_data;
    unsigned int asm_size;
#endif
    void * c_func;
};

struct Patch
{
#ifdef IS_X64
    unsigned char * asm_data;
    unsigned int asm_size;
#endif
    void * c_func;
    uint32_t patch_addr;
    uint32_t patch_table;
};

struct DirectPatch
{
    uint32_t patch_addr;
    unsigned char * asm_data;
    unsigned int asm_size;
};

extern std::unordered_map<std::string, Import> imports;
extern std::vector<Patch> patches;