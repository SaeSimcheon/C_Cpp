#include <stdio.h>


int main(){
    int total;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int arr1[] = {2,10,30,21,34,23,53,21,9,1};
    scanf("%d",&total);
    
    int arr2[total]; // c11이후로 가능
    int i ;
    
    
    arr2[0]=1;
    printf("Array2 1 번째 원소 : %d \n", arr2[0]);
    
    printf("Array 3 번째 원소 : %d \n", arr[11]);
    
    
    for ( i = 0 ; i < 10 ; i ++ ){
        printf("배열의 %d번째 원소 : %d \n", i +1 , arr1[i]);
        
        
    }
    
    return 0;
}