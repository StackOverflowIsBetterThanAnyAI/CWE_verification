
/* add header files */
#include <stdlib.h>

#define BUFFER_SIZE 20
#define MESSAGE_SIZE 20

struct ExMessage
{
    char *msgBody;
    int msgLength;
};

/* example function must be declared here*/

int cwe_126_example1(int);
int cwe_126_example2(int, char **);
