#include "../include/CWE_415.h"

/* CWE-415
 * NAME: Double Free
 * Description: The product calls free() twice on the same memory address, potentially leading to modification of unexpected memory locations.
 * Link:https://cwe.mitre.org/data/definitions/415.html
 */

/*
 * Example 1
 *
 * The following code shows a simple example of a double free vulnerability.
 */ 

void double_free(bool abrt){
  char* ptr = (char*)malloc (SIZE);
  if (abrt) {
    free(ptr);
  }
  free(ptr);
}


/*
 * Example 2
 *
 * While contrived, this code should be exploitable on Linux distributions that do not ship 
 * with heap-chunk check summing turned on.
 */ 

int buf_free(int argc, char **argv) {
  char *buf1R1;
  char *buf2R1;
  char *buf1R2;
  buf1R1 = (char *) malloc(BUFSIZE2);
  buf2R1 = (char *) malloc(BUFSIZE2);
  free(buf1R1);
  free(buf2R1);
  buf1R2 = (char *) malloc(BUFSIZE1);
  strncpy(buf1R2, argv[1], BUFSIZE1-1);
  free(buf2R1);
  free(buf1R2);

  return 0;
}
