#include <proof_helpers/proof_helper.h>

// STRING

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

/*
 * realizaion of is_valid function of various types.  
 */ 

bool is_valid_int_array(int* int_array){
  return (int_array != NULL);
}

bool is_valid_float_array(float* float_array){
  return (float_array != NULL);
}

bool is_valid_double_array(double* double_array){
  return (double_array != NULL);
}

bool is_valid_char_array(char* string){
  return (string != NULL);
}

bool is_valid_char_double_pointer(char** double_pointer){
  return (double_pointer != NULL && *double_pointer != NULL);
}

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

char** ensure_malloc_char_double_pointer(int num, int len){
    char** str_array = (char**)malloc( num * sizeof(char*) );
    if(str_array == NULL) return NULL;
    for(int i = 0; i < num; i++){
        str_array[i] = (char*) malloc((len + 1) * sizeof(char) );
        if(str_array[i] == NULL) return NULL;
    }

    return str_array;
}

