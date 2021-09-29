#include <iostream>



int main(){
    char c ='a';
    char & b = c; 
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    b= 'c';
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    char d ; 
    d = b; // 참조변수인 b를 이용해서 d에 c를 복제했을 뿐임. 참조로 연결되지 않음.
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    d = 'k'; 
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    char & e = b; 
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;

    e='u'; // c에 별명이 하나더 생긴 것임.
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;

    return 0;
}

