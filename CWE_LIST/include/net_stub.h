
#include <arpa/inet.h>
#include <stdlib.h>

struct hostent {
    char *h_name;
};

struct hostent *gethostbyaddr(char *s, uint64_t size, int flag)
{
    struct hostent *res = (struct hostent *)malloc(sizeof(struct hostent));
    // __CPROVER_assume(res != NULL);
    res->h_name = "x";
    return res;
}