#include <stdio.h>

int main(){
    double i,j;
    
    printf("두 정수 입력: \n");
    
    scanf("%lf %lf",&i,&j);
    
    if (j == 0){
        printf("0으로 나눌 수 없습니다.");
        return 0 ;
    }
    
    printf("%f를 %f로 나눈 결과 : %f \n",i,j,i/j);
    
    return 0 ;
    
}