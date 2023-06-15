
#include "CWE_124.h"

/**
 * @attention need to verify
 */
char *cwe_124_example1(char *strMessage, int length)
{
    char *retMessage;

    // copy input string to a temporary string
    char message[length + 1];
    int index;
    for (index = 0; index < length; index++)
    {
        message[index] = strMessage[index];
    }
    message[index] = '\0';

    // trim trailing whitespace
    int len = index - 1;
    while (isspace(message[len]))
    {
        message[len] = '\0';
        len--;
    }

    // return string without trailing whitespace
    retMessage = message;
    return retMessage;
}

/**
 * @attention need to verify
 */
int find(char *s, char c) {
    int t;
    __CPROVER_assume(t < 10);
    return t;
}

/**
 * @attention need to verify
 */
void cwe_124_example2() {
    char destBuf[10];
    char srcBuf[10];
    char ch;
    strncpy(destBuf, &srcBuf[find(srcBuf, ch)], 1024);
}

