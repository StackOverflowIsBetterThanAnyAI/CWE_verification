#include "proof_helpers/proof_helper.h"

// STRING

bool is_valid_string(char* string){
  return (string != NULL);
}

bool is_nonempty_string(char* string){
  return strlen(string) > 0;
}


char* ensure_malloc_string(int len){
  char* str = malloc(sizeof(char) * len);
  if(str == NULL){
    return NULL;
  }

  for(int i = 0;i < len; i++){
    str[i] = nondet_char();
  }

  return str;
}

// ARRAY
int* ensure_malloc_int_array(int len){
  int* int_array = (int*)malloc(sizeof(int) * len);
  if(int_array == NULL){
    return NULL;
  }

  for(int i = 0; i < len; i++){
    int_array[i] = nondet_int();
  }

  return int_array;
}

bool is_valid_int_array(int* int_array){
  return (int_array != NULL);
}


char** ensure_malloc_double_pointer(int size){
  char* first_hierarchy = (char*)malloc(sizeof(char) * size );
  if(first_hierarchy == NULL){
    return NULL;
  }

  return &first_hierarchy;
}

bool is_valid_double_pointer(char** double_pointer){
  return (double_pointer != NULL && *double_pointer != NULL);
}
