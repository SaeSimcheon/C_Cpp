#include <iostream>

int main(){
    int a, b;
    //int & arr[2] = {a,b};
    //error: declaration of 'arr' as array of references
    int arr[3] = {1,2,3};
    int arr1[3][2] = {1,2,3,4,5,6};
    int(&ref)[3]=arr;

    ref[0]=2;
    ref[1]=3;
    ref[2]=1;

    std::cout <<arr[0] << arr[1] << arr[2] <<std::endl;
    std::cout <<arr1[0][1] << arr1[1][1] << arr1[2][1] <<std::endl;
    return 0;
}