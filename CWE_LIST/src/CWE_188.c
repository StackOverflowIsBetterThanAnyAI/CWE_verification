
#include "CWE_188.h"

/**
 * @attention need to verify
 */
void cwe_188_example1()
{
    char a;
    char b;
    *(&a + 1) = 0;
    __CPROVER_assert(b == 1, "b shoule be 1");
}
