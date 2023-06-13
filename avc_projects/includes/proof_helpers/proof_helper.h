#pragma once

/* 在下方添加验证基准文件中所需的头文件或代码 */
#include <string.h>
#include <stdlib.h>

// STRING

char* ensure_malloc_string(int);

bool is_valid_string(char*);

bool is_nonempty_string(char*);


// ARRAY
int* ensure_malloc_int_array(int);

bool is_valid_int_array(int*);

bool is_nonempty_int_array(int*);

char** ensure_malloc_double_pointer(int size);

bool is_valid_double_pointer(char** double_pointer);
