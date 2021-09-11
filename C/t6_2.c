#include <stdio.h>

int main(){
    int num ;
    
    printf("아무수 \n");
    scanf("%d",&num);
    
    
    if (num == 7){
        printf("행운아 \n");
    }else if (num==4){
        printf("불운아 \n");
    }else{
        printf("지나가세요 \n");
    }
}