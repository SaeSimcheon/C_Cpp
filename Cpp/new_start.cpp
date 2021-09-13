#include <iostream>


int main(){
    int* p = new int; //
    *p = 10;
    const int & a = 5;
    const int & b = 6; // 리거 리터럴 주소 맞음 4차이남
    const int & c = 6; // 리거 리터럴 주소 맞음 4차이남
    
    
    
    
    std::cout << &a << std::endl; // 이건 가능하네
    std::cout << &b << std::endl; // 이건 가능하네
    std::cout << &c << std::endl; // 이건 가능하네
    
    
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << &p << std::endl;
    
    delete p ;
    return 0;
}