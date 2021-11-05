#include <iostream>

int main(){
    int a = 10;

    //# 레퍼런스는 정의와 동시에 초기화 되어야한다.

    // int & aa; 
    //cruch2_4.cpp:5:11: error: 'aa' declared as reference but not initialized
    int & another =a ;
    int b = 3;
    int *c ;

    std::cout << c <<std::endl; // 문제 없이 선언됨

    //# 레퍼런스는 한 번 정해지면 바뀌지 않는다.
    std::cout << a <<std::endl;
    std::cout << another <<std::endl;
    // int &another =b;
    // cruch2_pointer_vs_reference.cpp:19:10: error: redeclaration of 'int& another'
    // 재선언 자체가 금지다.

    another=b; // 포인터와 비슷하게 하려고 해도 불가능하다. 
    // 값의 복사가 일어날 뿐이다.
    std::cout << a <<std::endl;
    std::cout << another <<std::endl;
    
    int *p = &a;
    std::cout << p <<std::endl;
    p = &b;
    std::cout << p <<std::endl; // 다른 변수의 주소를 가질 수 있음

    //# 레퍼런스는 메모리상에 존재하지 않을 수도 있다.

}