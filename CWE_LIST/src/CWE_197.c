
#include "CWE_197.h"

void cwe_197_example1()
{
    int intPrimitive;
    short shortPrimitive;
    intPrimitive = (int)(~((int)0) ^ (1 << (sizeof(int) * 8 - 1)));
    shortPrimitive = intPrimitive;
}
