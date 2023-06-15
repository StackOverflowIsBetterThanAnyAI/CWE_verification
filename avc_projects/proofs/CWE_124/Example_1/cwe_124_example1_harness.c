
#include "proof_helpers/proof_helper.h"
#include "CWE_124.h"

void harness(void)
{

	/* 初始化函数变量 */

	/* 前置条件 */
	char *strMessage = malloc(30);
	__CPROVER_assume(strMessage != NULL);
	int length = 20;

	cwe_124_example1(strMessage, length);

	/* 后置条件 */
}
