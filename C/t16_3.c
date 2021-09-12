#include <stdio.h>

struct test{
    int c;
    int *pointer ;
    
};


int main(){
    
    struct test t;
    struct test *pt = &t;
    
    int i = 0 ;
    
    t.pointer = &i;
    
    *t.pointer = 3;
    
    printf("i : %d \n", i );
    
    
    *pt -> pointer = 4;
    
    printf("i : %d \n ", i );
    
    return 0 ; 
}