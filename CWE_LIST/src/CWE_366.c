
#include "CWE_366.h"

int foo = 0;

/**
 * @attention need to verify
 */
void cwe_366_example1(int num)
{
    static int counter = 0;
    counter++;
    if (num > foo)
        foo = num;
    return foo;
}
