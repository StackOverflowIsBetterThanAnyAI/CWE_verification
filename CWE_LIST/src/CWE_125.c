
#include "../include/CWE_125.h"

/**
 * @attention need to verify
 */
int cwe_125_example1(int *array, int len, int index)
{

    int value;

    // check that the array index is less than the maximum

    // length of the array
    if (index < len)
    {

        // get the value at the specified index of the array
        value = array[index];
    }
    // if array index is invalid then output error message

    // and return value indicating error
    else
    {
        printf("Value is: %d\n", array[index]);
        value = -1;
    }

    return value;
}