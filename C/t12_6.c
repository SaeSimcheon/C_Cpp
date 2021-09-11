#include <stdio.h>



int main(){
    int arr[3] = {1,2,3};
    int (*parr)[3] = &arr; // 배열의 포인터
    // int parr2 = &arr; 이건 불가능함. & 연산자가 붙었을때는 배열의 첫번째 원소의 주소로 인정 안 함
    
    printf("arr[1] : %d \n",arr[1]);
    printf("arr[2] : %d \n",arr[1]);
    
    printf("&arr[1] : %p \n",&arr[1]);
    printf("&arr[2] : %p \n",&arr[2]);
    
    printf("&(arr[1]) : %p \n",&(arr[1]));
    printf("&(arr[2]) : %p \n",&(arr[2]));
    
    
    printf("(*parr)[1] : %d \n",(*parr)[1]);
    printf("*parr[1] : %d \n",*parr[1]);
    
    
    printf("&parr : %p \n",&parr); // 이건 다름 parr의 주소 반환
    printf("*parr : %p \n",*parr);
    printf("(*parr)[0] : %d \n",(*parr)[0]);
    
    printf("parr : %p \n",parr); // 포인터이고 배열 아님.
    printf("parr[0] : %p \n",parr[0]);
    printf("parr[1] : %p \n",parr[1]);
    printf("parr[2] : %p \n",parr[2]);
}