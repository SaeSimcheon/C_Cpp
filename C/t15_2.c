#include <stdio.h>

int length(char[]);

int main(){
    //char str[];
    char str[] = {"hello"}; 
    //scanf('%s',&str);
    printf("%ld",sizeof(str) - 1);
    //printf("%d",sizeof(str)/sizeof(char) -1);
    
    return 0 ;
    
}

//int length(char given[]){
//    return sizeof(given)/sizeof(char) -1;
//}