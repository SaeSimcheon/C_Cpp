#include <iostream>

/*
int change(int *p){
    *p = 3;
    return 0 ;
}
*/

int change(int &p){
    p = 3;
    return 0 ;
}

int main(){
    int number = 5;
    //int& another = number ;
    
    std::cout << number << std::endl;
    //std::cout << another << std::endl;
    //change(&number); 이건 포인터 용
    change(number); // 참조자용
    std::cout << number << std::endl;
    //std::cout << another << std::endl;
    return 0;
}