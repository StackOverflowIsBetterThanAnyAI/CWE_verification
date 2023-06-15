
#include "proof_helpers/proof_helper.h"
#include "CWE_362.h"

void harness(void)
{

	/* 初始化函数变量 */

	/* 前置条件 */

	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

	cwe_362_example2(&mutex);

	/* 后置条件 */

}
