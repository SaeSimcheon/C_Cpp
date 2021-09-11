#include <stdio.h>

int main(){
    int a ;
    a = 10 ;
    printf("%d\n",a);
    
    int b ; 
    b= 127;
    
    printf("%d %o \n",b,b);
    printf("%d %d \n",b,b);
    printf("%d %x \n",b,b);
    
    
    
    float c =3.141592f;
    float d =3.141592;
    
    printf("%f\n",c);
    printf("%f\n",d);
    
    int e = 123 ;
    
    printf("%.2f\n",c);
    printf("%5d\n",e);
    printf("%6.3f\n",d);
    
    return 0;
}