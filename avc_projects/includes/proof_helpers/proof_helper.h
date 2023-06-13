#pragma once

/* 在下方添加验证基准文件中所需的头文件或代码 */
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// STRING

char* ensure_malloc_string(int);

bool is_valid_string(char*);

bool is_nonempty_string(char*);


// ARRAY

/*
 * IS_VALID_ARRAY FUNCTION
 *
 * validity of an array, of any type.
 */ 

#define IS_VALID_ARRAY(X) _Generic((X),     \
  int*    : is_valid_int_array,             \
  float*  : is_valid_float_array,           \
  double* : is_valid_double_array,          \
  char*   : is_valid_char_array,            \
  char**  : is_valid_char_double_pointer,   \
  default : throw_error                     \
  )(X)

bool is_valid_int_array(int*);
bool is_valid_float_array(float*);
bool is_valid_double_array(double*);
bool is_valid_char_array(char*);
bool is_valid_char_double_pointer(char** double_pointer);
bool throw_error();

int* ensure_malloc_int_array(int);
char** ensure_malloc_char_double_pointer(int num, int len);

