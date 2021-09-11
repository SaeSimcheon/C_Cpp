#include <stdio.h>


int main(){
    int arr[3][2] = {1,2,3,4,5,6};
    int i ,j;
    //int arr1[2][] = {{4,5,6},{4,5,6}}  ;   오류 
    //declaration of ‘arr1’ as multidimensional array must have bounds for all dimensions except the first
    
    for (i = 0 ;i < 3 ; i++){
        for (j = 0 ; j < 2 ; j ++){
            printf("%d",arr[i][j]);
        }
    }
}