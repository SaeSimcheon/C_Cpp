#include <stdio.h>


int main(){
    
    int a =3;
    //const int a =3;
    int b = 4; 
    const int* pa = &a;
    
    
    //*pa = 4;
    a = 4;
    printf("%d",*pa);
    pa = &b;
    
    printf("%d",*pa);
}