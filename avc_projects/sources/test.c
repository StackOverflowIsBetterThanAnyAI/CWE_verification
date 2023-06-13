// used for performing some CBMC testing 

#include <stdlib.h>

int main(){
    int len = 5;
    int* a = (char*)malloc(len*(sizeof(char)));
    __CPROVER_assume(a != NULL);
    
    __CPROVER_havoc_object(a);

    __CPROVER_assert(a[3] == 'a', "wrong" );

    return 0;
}