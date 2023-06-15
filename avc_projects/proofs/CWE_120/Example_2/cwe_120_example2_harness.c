
#include "proof_helpers/proof_helper.h"
#include "CWE_120.h"

void harness(void)
{

	/* 初始化函数变量 */

	/* 前置条件 */
	char *s = malloc(30);
	__CPROVER_assume(s != NULL);

	cwe_120_example2(s);

	/* 后置条件 */

}
