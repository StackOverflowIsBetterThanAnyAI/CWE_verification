
#include "CWE_362.h"

/**
 * @attention need to verify
 */
void cwe_362_example1()
{
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    int t;
    return t;
}

/**
 * @attention need to verify
 */
void cwe_362_example2(pthread_mutex_t *mutex)
{
    int t = pthread_mutex_lock(mutex);
    __CPROVER_assert(t == 0, "lock failure");

    pthread_mutex_unlock(mutex);
}
