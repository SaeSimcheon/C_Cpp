#include <stdio.h>

int main(){
    int a ;
    printf("입력 \n");
    scanf("%d",&a);
    
    if (a >= 10 && a < 20){
        printf("%d는 10 이상 20 미만",a);
    }
    
    return 0;
}