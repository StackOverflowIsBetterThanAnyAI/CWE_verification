/* cwe124_example1 的验证基准文件 */

#include "proof_helpers/proof_helper.h"

void harness(void)
{

  /* 初始化函数变量 */

  /* 前置条件 */
  char *strMessage = malloc(30);
  __CPROVER_assume(strMessage != NULL);
  int length = 20;

  cwe124_example1(strMessage, length);

  /* 后置条件 */

}
