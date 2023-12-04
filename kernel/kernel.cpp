#include "include/common/types.hpp"

typedef void (*constructor)();
extern "C" constructor* start_ctors;
extern "C" constructor* end_ctors;
extern "C" void CallConstructors()
{
    for(constructor* i = start_ctors; i != end_ctors; i++)
        (*i)();
}

extern "C" void KernelMain(void* multiboot_structure, uint32_t magicnumber)
{

    while(true);
}