
#include "CWE_128.h"

/**
 * @attention need to verify
 */
void cwe_128_example1()
{
    img_t table_ptr;
    int num_imgs;

    num_imgs = get_num_imgs();
    table_ptr = (img_t *)malloc(sizeof(img_t) * num_imgs);
}
