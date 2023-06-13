
#include "../include/CWE_120.h"

/**
 * example1
 * need an abstract of scanf
 */
int scanf(const char *s1, char *s2)
{
    int i = 0;
    while (1)
    {
        char c;
        if (c == ' ' || c == '\n')
            break;
        s2[i++] = c;
    }
    return i;
}

/**
 * @attention need to verify
 */
void cwe120_example1()
{
    char last_name[20];
    printf("Enter your last name: ");
    scanf("%s", last_name);
}

/**
 * example2
 * need an abstarct of strcpy
 */

/**
 * @attention need to verify
 */
void cwe120_example2(char *string)
{
    char buf[24];
    strcpy(buf, string);
}

/**
 * example3 is similar to example1
 */

/**
 * example4
 * abstracts of gethostbyaddr and close
 */
struct hostent *gethostbyaddr(char *s, uint64_t size, int flag)
{
    struct hostent *res = malloc(sizeof(struct hostent));
    __CPROVER_assume(res != NULL);
    res->h_name = malloc(30);
    __CPROVER_assume(res->h_name != NULL);
    return res;
}

void close(int fd) {}

void cwe120_example4()
{
    struct hostent *clienthp;
    char hostname[MAX_LEN];

    int serversocket;
    struct sockaddr_in clientaddr;

    int count = 0;
    for (count = 0; count < MAX_CONNECTIONS; count++)
    {

        int clientlen = sizeof(struct sockaddr_in);
        int clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &clientlen);

        if (clientsocket >= 0)
        {
            clienthp = gethostbyaddr((char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
            strcpy(hostname, clienthp->h_name);
            logOutput("Accepted client connection from host ", hostname);

            // process client request
            close(clientsocket);
        }
    }
    close(serversocket);
}
