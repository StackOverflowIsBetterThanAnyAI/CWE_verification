/* buf_free 的验证基准文件 */

#include "proof_helpers/proof_helper.h"
#include "include/CWE_415.h"

void harness(void)
{

  /* 初始化函数变量 */
  int argc;
  int num;
  int len;
  __CPROVER_assume(num > 1 && len > 0 && num <= 3 && len <= 20); // control the capacity of the input

  do_nothing(len);

  char** argv = ensure_malloc_char_double_pointer(num, len);

  __CPROVER_assume(IS_VALID_ARRAY(argv));

  buf_free( argc, argv);

}