#include <stdio.h>

int add_one(int *a );

struct test{
    int c;
};


int main(){
    struct test t ;
    struct test *pt = &t;
    
    pt ->c = 0 ;
    
    add_one(&t.c);
    
    printf("t.c : %d \n",t.c);
    
    
    add_one(&pt -> c);
    
    printf("t.c : %d \n",t.c);
    
    return 0;
}


int add_one(int *a){
    *a +=1;
    
    return 0 ;
}