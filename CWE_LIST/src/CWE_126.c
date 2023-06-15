
#include "CWE_126.h"

struct ExMessage *recastBuffer(buffer)
{
    struct ExMessage *res = (struct ExMessage *)malloc(sizeof(struct ExMessage));
    __CPROVER_assume(res != NULL);
    res->msgBody = (char *)malloc(30);
    __CPROVER_assume(res->msgBody != NULL);
    res->msgLength = 30;
    return res;
}

/**
 * @attention need to verify
 */
int cwe_126_example1(int socket)
{
    int success;

    char buffer[BUFFER_SIZE];
    char message[MESSAGE_SIZE];

    // get message from socket and store into buffer

    // Ignoring possibliity that buffer > BUFFER_SIZE
    if (getMessage(socket, buffer, BUFFER_SIZE) > 0)
    {

        // place contents of the buffer into message structure
        struct ExMessage *msg = recastBuffer(buffer);

        // copy message body into string for processing
        int index;
        for (index = 0; index < msg->msgLength; index++)
        {
            message[index] = msg->msgBody[index];
        }
        message[index] = '\0';

        // process message
        success = processMessage(message);
    }
    return success;
}

size_t strnlen(const char *s, size_t max_len)
{
    __CPROVER_size_t len = 0;
    while (len < max_len && s[len] != 0)
        len++;
    return len;
}

/**
 * @attention need to verify
 */
int cwe_126_example2(int argc, char **argv)
{
    char Filename[256];
    char Pattern[32];

    /* Validate number of parameters and ensure valid content */

    /* copy filename parameter to variable, may cause off-by-one overflow */
    strncpy(Filename, argv[1], sizeof(Filename));
    __CPROVER_assert(strnlen(Filename, 256) < 256, "len shoule less than 256");

    /* copy pattern parameter to variable, may cause off-by-one overflow */
    strncpy(Pattern, argv[2], sizeof(Pattern));
    __CPROVER_assert(strnlen(Pattern, 256) < 256, "len shoule less than 32");

    printf("Searching file: %s for the pattern: %s\n", Filename, Pattern);
    Scan_File(Filename, Pattern);
}
