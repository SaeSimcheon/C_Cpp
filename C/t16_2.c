#include <stdio.h>


struct test{
    int c;
};


int main(){
    struct test t;
    struct test *pt = &t;
    
    
    (*pt).c = 0 ;
    
    
    printf("t.c : %d \n", t.c);
    
    
    pt ->c =1;
    
    printf("t.c : %d \n", t.c);
    
    return 0;
}