
#include "CWE_190.h"

/**
 * example 1
 */

/**
 * @attention need to verify
*/
void cwe_190_example1()
{
    img_t *table_ptr;
    int num_imgs;
    num_imgs = get_num_imgs();
    table_ptr = (img_t *)malloc(sizeof(img_t) * num_imgs);
}

/**
 * example 2
 */

char **xmalloc(unsigned int size)
{
    char **res = malloc(size);
    __CPROVER_assume(res != NULL);
    return res;
}

char *packet_get_string(void *p)
{
    char *res = (char *)malloc(8);
    __CPROVER_assume(res != NULL);
    return res;
}

/**
 * @attention need to verify
*/
void cwe_190_example2()
{
    int nresp;
    char **response;
    nresp = packet_get_int();
    if (nresp > 0)
    {
        response = xmalloc(nresp * sizeof(char *));
        for (int i = 0; i < nresp; i++)
        {
            response[i] = packet_get_string(NULL);
        }
    }
}

/**
 * example3
 */
int getFromInput(char *s)
{
    s[0] = '0';
    s[1] = '0';
    return 2;
}

/**
 * @attention need to verify
*/
void cwe_190_example3()
{
    short int bytesRec = 0;
    char buf[SOMEBIGNUM];

    while (bytesRec < MAXGET)
    {
        bytesRec += getFromInput(buf + bytesRec);
    }
}

/**
 * example4
 */

short getMonthlySales(int month) {}

float calculateRevenueForQuarter(short quarterSold) {}

/**
 * @attention need to verify
*/
int cwe_190_example4()
{

    // Variable for sales revenue for the quarter
    float quarterRevenue = 0.0f;

    short JanSold = getMonthlySales(JAN); /* Get sales in January */
    short FebSold = getMonthlySales(FEB); /* Get sales in February */
    short MarSold = getMonthlySales(MAR); /* Get sales in March */

    // Calculate quarterly total
    short quarterSold = JanSold + FebSold + MarSold;

    // Calculate the total revenue for the quarter
    quarterRevenue = calculateRevenueForQuarter(quarterSold);

    saveFirstQuarterRevenue(quarterRevenue);

    return 0;
}