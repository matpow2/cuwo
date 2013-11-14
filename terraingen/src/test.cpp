#include "main.h"
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

// inline includes
#include "cpu.cpp"
#include "memory.cpp"

CPU cpu;
Memory mem;

uint8_t asm_of, asm_zf, asm_sf, asm_cf;
uint32_t asm_eax;

inline void test_zf()
{
    if (int(cpu.get_zf()) == asm_zf)
        return;
    std::cout << "Invalid ZF" << std::endl;
    exit(0);
}

inline void test_sf()
{
    if (int(cpu.get_sf()) == asm_sf)
        return;
    std::cout << "Invalid SF" << std::endl;
    exit(0);
}

inline void test_of()
{
    if (int(cpu.get_of()) == asm_of)
        return;
    std::cout << "Invalid OF" << std::endl;
    exit(0);
}

inline void test_cf()
{
    if (int(cpu.get_cf()) == asm_cf)
        return;
    std::cout << "Invalid CF" << std::endl;
    exit(0);
}

inline void test_eax()
{
    if (cpu.reg[EAX] == asm_eax)
        return;
    std::cout << "Invalid EAX" << std::endl;
    exit(0);
}

inline void test_flags()
{
    test_of();
    test_sf();
    test_zf();
    test_cf();
}

#define PUSH_REGS() __asm__("push %eax\n\t")
#define POP_REGS() __asm__("movl %eax, _asm_eax\n\t"\
                           "seto _asm_of\n\t"\
                           "setc _asm_cf\n\t"\
                           "setz _asm_zf\n\t"\
                           "sets _asm_sf\n\t"\
                           "pop %eax\n\t")

int main(int argc, const char ** argv)
{
    std::cout << "Running tests" << std::endl;

    // add
    // dword
    cpu.add_dword(-5, -2);
    PUSH_REGS();
    __asm__("movl $-5, %eax");
    __asm__("addl $-2, %eax");
    POP_REGS();
    test_flags();


    cpu.add_dword(-2, 2);
    PUSH_REGS();
    __asm__("movl $-2, %eax");
    __asm__("addl $2, %eax");
    POP_REGS();
    test_flags();

    // add
    // byte
    cpu.add_byte(-5, -2);
    PUSH_REGS();
    __asm__("mov $-5, %ax");
    __asm__("add $-2, %ax");
    POP_REGS();
    test_flags();

    std::cout << "Done" << std::endl;
    return 0;
}