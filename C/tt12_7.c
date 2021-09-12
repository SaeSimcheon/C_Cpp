#include <stdio.h>


int main(){
    int arr[2][3] = {{1,2,3},{4,5,6}} ;
    int arr1[3] = {1,2,3};
    /*
    int *parr ;
    parr = arr;
tt12_7.c: In function ‘main’:
tt12_7.c:9:10: warning: assignment to ‘int *’ from incompatible pointer type ‘int (*)[3]’ [-Wincompatible-pointer-types]
    */
    
    
    int (*parr)[2][3];
    parr = &arr;
    printf("%p \n",parr[1][1]);
    
    
    
    //int (*parr)[3];
    
    //parr = arr;
    
    int (*parr1)[3];
    parr1 = &arr1;
    //parr1 = arr1; 이 방식은 안 됨
    /*
    한가지 특이한 점이 parr[0],parr[1] 까지는 포인터인데 parr[0][0] 등은 배열의 원소 값을 반환함
    */
    
    
    printf("일차원\n");
    
    printf("%p \n",arr1);
    printf("%d \n",arr1[0]);
    printf("%d \n",arr1[1]);
    printf("%p \n",parr1);
    printf("%p \n",parr1[0]);
    //printf("%p \n",parr[1][1]);
    printf("%p \n",parr1[1]);
    
    
    
    
    
    printf("이차원\n");
    
    printf("%p \n",arr);
    printf("%p \n",arr[0]);
    printf("%p \n",arr[1]);
    printf("%p \n",parr);
    printf("%p \n",parr[1]);
    //printf("%p \n",parr[1][1]);
    printf("%p \n",parr[0]);
    //printf("%d \n",parr[1][1]);
    printf("%p \n",parr[1][1]);
    return 0;
}