#include <stdio.h>


int change(int *pi){
    printf("함수 안에서 \n");
    printf("pi의 값: %p \n",pi);
    printf("pi가 가리키는 값 : %d \n",*pi);
    
    *pi=3;
    
    printf("change 끝 \n");
    
    return 0 ; 
}


int main(){
    int i = 0;
    
    printf("i변수의 주소값 : %p \n", &i);
    printf("호출 이전의 값 : %d \n", i);
    change(&i);
    
    printf("호출 이후의 값 : %d \n", i);
}