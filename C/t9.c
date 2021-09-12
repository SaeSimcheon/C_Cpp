 #include <stdio.h>


int main(){
    int input ; 
    
    printf("1. 밥주기 \n");
    printf("2. 씻기기 \n");
    printf("3. 재우기 \n");
    
    scanf("%d",&input);
    
    switch(input){
        case 1 :
            printf("맛나\n");
        case 2 :
            printf("시원해\n");
        case 3 :
            printf("zzz\n");
        default :
            printf("월월\n");
            
            
    }
    return 0;
    
}