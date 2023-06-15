
#include "proof_helpers/proof_helper.h"
#include "CWE_126.h"

void harness(void)
{

	/* 初始化函数变量 */

	/* 前置条件 */
	int argc = 3;
	char **argv = (char **)malloc(3 * sizeof(char *));
	__CPROVER_assume(argv != NULL);

	argv[1] = (char *)malloc(300);
	__CPROVER_assume(argv[1] != NULL);
	argv[1][299] = '\0';

	argv[2] = (char *)malloc(40);
	__CPROVER_assume(argv[2] != NULL);
	argv[2][39] = '\0';

	cwe_126_example2(argc, argv);

	/* 后置条件 */
}
