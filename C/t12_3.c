#include <stdio.h>


int main(){
    
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    int* parr ;
    int i ;
    
    parr = &arr[0];
    
    
    printf("%p \n ",arr);
    printf("%p \n",&arr[0]);
    /*
    for (i = 0 ; i < 10 ; i ++){
        printf("add[%d]의 주소값 : %p \n",i,&arr[i]);
        printf("add[%d]의 값 : %d \n",i,arr[i]);
        printf("(parr + %d)의 주소값 : %p \n",i,parr + i);
        printf("(parr + %d)이 가리키는 값 : %d \n",i,*(parr + i));
    }
    */
    
}