
#include "CWE_364.h"

char *logMessage;

void handler(int sigNum)
{
    // syslog(LOG_NOTICE, "%s\n", logMessage);
    free(logMessage);
    // sleep(10);
    // exit(0);
}

size_t strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != 0)
        len++;
    return len;
}

char *strdup(const char *str)
{
    size_t t = strlen(str);
    __CPROVER_printf("%d", t);
    char *res = malloc(t + 1);
    __CPROVER_assume(res);
    strcpy(res, str);
    return res;
}

/**
 * @attention need to verify
 */
void cwe_364_example1(int argc, char **argv)
{
    logMessage = strdup(argv[1]);
    handler(0);
    handler(0);
    // sleep(10);
    // exit(0);
}

/**
 * @attention need to verify
 * same as example1
 */
void cwe_364_example2()
{
}
