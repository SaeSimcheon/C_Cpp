#include <stdio.h>
#include <math.h>


int main(){
    int *p;
    int a ;
    a= 2;
    
    
    p = &a;
    printf("%p \n", p);
    printf("%p \n", &a);
    
    printf("%d \n", a);
    printf("%d \n", *p);
    
    printf("%f",pow(2,64));
    return 0;
}