
#include "proof_helpers/proof_helper.h"
#include "CWE_125.h"

void harness(void)
{

	/* 初始化函数变量 */

	/* 前置条件 */
	int *array = malloc(sizeof(int) * 20);
	__CPROVER_assume(array != NULL);
	int len;
	int index;

	cwe_125_example1(array, len, index);

	/* 后置条件 */
}
