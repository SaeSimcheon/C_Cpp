#include <stdio.h>

int change(int (*parr)[3],int idx1,int idx2,int given); //

int main(){
    int arr[2][3] = {{1,2,3},{4,5,6}};
    
    printf("idx1 : %d ,idx2 : %d ,given : %d,origin : %d  \n",1,1,10,arr[1][1]);
    
    change(arr,1,1,10);
    
    printf("idx1 : %d ,idx2 : %d ,given : %d,changed : %d \n ",1,1,10,arr[1][1]);
    
    
    return 0 ;
}


int change(int (*parr)[3],int idx1,int idx2,int given){
    
    parr[idx1][idx2] =given;
    
    
    return 0;
}