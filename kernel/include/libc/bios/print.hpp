#ifndef __PRINTF_BASIC__
#define __PRINTF_BASIC__
#include "../../common/types.hpp"
namespace bios
{
    namespace print
    {
        
        void printf(char* string);
        void printf(char* string, char* color);
    }
}
#endif