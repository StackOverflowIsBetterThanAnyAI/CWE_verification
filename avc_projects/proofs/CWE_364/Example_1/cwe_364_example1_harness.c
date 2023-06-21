
#include "proof_helpers/proof_helper.h"
#include "CWE_364.h"

void harness(void)
{

	/* 初始化函数变量 */

	/* 前置条件 */
	int argc;
	char **argv = malloc(sizeof(char *) * 2);
	__CPROVER_assume(argv != NULL);
	argv[1] = malloc(10);
	__CPROVER_assume(argv[1] != NULL);
	argv[1][9] = '\0';

	cwe_364_example1(argc, argv);

	/* 后置条件 */

}
