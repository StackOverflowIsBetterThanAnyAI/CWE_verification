/* double_free 的验证基准文件 */

#include "proof_helpers/proof_helper.h"
#include "include/CWE_415.h"

void harness(void)
{

  /* 初始化函数变量 */
  bool abrt;

  /* 前置条件 */

  double_free( abrt );

  /* 后置条件 */

}
