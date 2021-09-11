#include <stdio.h>

int main(){
    int a = 10 ; 
    int b = 4 ; 
    
    printf("+ %d\n",a+b);
    printf("- %d\n",a-b);
    printf("* %d\n",a*b);
    printf("/ %d\n",a/b);
    printf("%% %d\n",a%b);
    
    /*
    int c = 10 ; 
    int d =  3; 
    
    printf("/ %f\n",c/d);
    */
    
    int c = 10 ; 
    double d =  3; 
    
    printf("/ %f\n",c/d); // 결국 이렇게 하면 원하는 실수연산 결과가 나옴
    
    return 0 ;
}