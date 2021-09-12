#include <stdio.h>


int main(){
    int arr[2][3] = {{1,2,3},{4,5,6}} ;
    int (*parr)[3];
    parr = arr;
    printf("%p \n",arr);
    printf("%p \n",parr);
    printf("%p \n",parr[0]);
    printf("%d \n",parr[0][0]);
    printf("%p \n",parr[1]);
    printf("%d \n",parr[1][0]);
    printf("%d \n",parr[1][1]);
    return 0;
}