
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 1
#define MAX_LEN 20

struct hostent {
    char *h_name;
};

