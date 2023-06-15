
#include "CWE_191.h"

/**
 * @attention need to verify
 */
int cwe_191_example1()
{
    int i;
    i = -2147483648;
    i = i - 1;
    return 0;
}

/**
 * @attention need to verify
 */
void cwe_191_example2()
{
    int a = 5, b = 6;
    size_t len = a - b;
    char buf[len];
}
