#include <stdio.h>

int main(){
    int i ;
    int j ;
    for (i = 0 ; i < 20 ; i ++){
        printf("숫자 : %d \n ",i);
    }
    
    
    for (i = 0 ; i < 10 ; i ++){
        printf("숫자 : %d \n ",i);
    }
    
    for (i = 0 ; i < 10 ; i ++){
        printf("컴퓨터가 원하는 숫자는? \n");
        scanf("%d",&j);
        
        if (j==7){
            printf("정확해");
            break;
        }else if(j==6 || j == 8){
            printf("조금 아쉬운데?");
            continue;
        }
    }
    
    
    return 0 ;
}