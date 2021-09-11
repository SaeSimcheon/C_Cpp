#include <stdio.h>

int main(){
    
    int i = 1, sum = 0,end = 100;
    
    while (i <= end){
        sum +=i;
        i++;
    }
    
    printf("1부터 %d까지의 합은 %d \n",end,sum);
    
    return 0;
}