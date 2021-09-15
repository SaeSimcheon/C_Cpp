#include<iostream>

int main(){
    
    
    int * p = new int;
    
    int arr[2][3] = {1,2,3,4,5,6};
    
    int (* aa)[3] = arr;
    int (* aaa)[2][3] = &arr;
    
    
    
    for(int i = 0 ; i < 3 ; i ++){ p[i]= i *10;}
    
    
    
    std::cout << p <<std::endl;
    std::cout << p[0] <<std::endl;
    std::cout << p[1] <<std::endl;
    std::cout << p[2] <<std::endl;
    std::cout << p[3] <<std::endl;
    std::cout << p[4] <<std::endl;
    std::cout << &p[100] <<std::endl;
    
    delete p;
    
    
    
    return 0;
}