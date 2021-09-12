#include <stdio.h>


int main(){
    char null_1 = '\0';
    char null_2 = 0;
    //char null_3 = (char)NULL;
    //int nn = NULL;
    
    char not_null = '0';
    
    
    
    char sentence_1[4] = {'P','P','P','\0'};
    char sentence_2[4] = {'P','P','P',0};
    char sentence_3[4] = {"PPP"};
    char sentence_4[4] = "PPP";
    
    printf("NULL의 정수(아스키) 값 : %d, %d \n ",null_1,null_2);
    //printf("NULL의 정수(아스키) 값 : %d, %d, %d \n ",null_1,null_2,null_3);
    printf("'0'의 정수(아스키) 값 : %d \n ",not_null);
    
    printf("s1 : %s \n ",sentence_1);
    printf("s1 : %p \n ",sentence_1);
    printf("s2 : %s \n ",sentence_2);
    printf("s3 : %s \n ",sentence_3);
    printf("s4 : %s \n ",sentence_4);
    
    
    
    
    return 0 ;
}