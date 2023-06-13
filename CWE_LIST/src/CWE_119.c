#include "../include/CWE_119.h"


/* CWE-119
 * NAME: Improper Restriction of Operations within the Bounds of a Memory Buffer
 * Description: Improper Restriction of Operations within the Bounds of a Memory Buffer
 * Link:https://cwe.mitre.org/data/definitions/119.html
 */


/*
 * Example 1
 *
 * This example takes an IP address from a user, verifies that it is well formed and then looks up the hostname and copies it into a buffer.
 * This function allocates a buffer of 64 bytes to store the hostname, however there is no guarantee that the hostname will not be larger than 64 bytes. If an attacker specifies an address which resolves to a very large hostname, then the function may overwrite sensitive data or even relinquish control flow to the attacker.
 */ 

void host_lookup(char *user_supplied_addr){
  struct hostent *hp;
  in_addr_t *addr;
  char hostname[64];
  // declared in header file↓
  // in_addr_t inet_addr(const char *cp);   

  /*routine that ensures user_supplied_addr is in the right format for conversion */

  validate_addr_form(user_supplied_addr);
  addr = inet_addr(user_supplied_addr);
  hp = gethostbyaddr( addr, sizeof(struct in_addr), AF_INET);
  strcpy(hostname, hp->h_name);
}

/* 
 * Example 2
 *
 * This example applies an encoding procedure to an input string and stores it into a buffer.
 * The programmer attempts to encode the ampersand character in the user-controlled string, 
 * however the length of the string is validated before the encoding procedure is applied. 
 * Furthermore, the programmer assumes encoding expansion will only expand a given character
 * by a factor of 4, while the encoding of the ampersand expands by 5. As a result, when 
 * the encoding procedure expands the string it is possible to overflow the destination 
 * buffer if the attacker provides a string of many ampersands.
 */ 

char * copy_input(char *user_supplied_string){
  int i, dst_index;
  char *dst_buf = (char*)malloc(4*sizeof(char) * MAX_SIZE);
  if ( MAX_SIZE <= strlen(user_supplied_string) ){
    die("user string too long, die evil hacker!");
    }
  dst_index = 0;
  for ( i = 0; i < strlen(user_supplied_string); i++ ){
    if( '&' == user_supplied_string[i] ){
      dst_buf[dst_index++] = '&';
      dst_buf[dst_index++] = 'a';
      dst_buf[dst_index++] = 'm';
      dst_buf[dst_index++] = 'p';
      dst_buf[dst_index++] = ';';
    }
    else if ('<' == user_supplied_string[i] ){
    /* encode to &lt; */
      dst_buf[dst_index++] = '&';
      dst_buf[dst_index++] = 'l';
      dst_buf[dst_index++] = 't';
      dst_buf[dst_index++] = ';';
    }
    else dst_buf[dst_index++] = user_supplied_string[i];
  }
  return dst_buf;
}


/*
 * Example 3
 *
 * The following example asks a user for an offset into an array to select an item.
 * The programmer allows the user to specify which element in the list to select,
 * however an attacker can provide an out-of-bounds offset, resulting in a buffer over-read.
 */ 
int select_item () {
  char *items[] = {"boat", "car", "truck", "train"};
  int index = GetUntrustedOffset();
  printf("You selected %s\n", items[index-1]);

  return 0;
}

/*
 * Example 4
 *
 * In the following code, the method retrieves a value from an array at a specific array 
 * index location that is given as an input parameter to the method.
 * However, this method only verifies that the given array index is less than the 
 * maximum length of the array but does not check for the minimum value (CWE-839). 
 * This will allow a negative value to be accepted as the input array index, 
 * which will result in a out of bounds read (CWE-125) and may allow access to 
 * sensitive memory. The input array index should be checked to verify that is 
 * within the maximum and minimum range required for the array (CWE-129).
 */ 

int getValueFromArray(int *array, int len, int index) {

  int value;

  // check that the array index is less than the maximum

  // length of the array
  if (index < len) {
  // get the value at the specified index of the array
    value = array[index];
  }
  // if array index is invalid then output error message
  // and return value indicating error
  else {
    printf("Value is: %d\n", array[index]);
    value = -1;
  }

  return value;
}

