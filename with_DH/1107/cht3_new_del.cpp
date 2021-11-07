#include <iostream>

int main(){
    int * p =new int ;
    int a = 0;
    std::cout << "p는 포인터다 " <<p << std::endl;
    std::cout << "p는 누구를 가리켜? " <<*p << std::endl;
    * p = 10;
    std::cout << "p는 누구를 가리켜? " <<*p << std::endl;
    // T * pointer new T ;의 형태로 메모리를 할당받는다.
    delete p;
    //delete a; 힙이 아닌 공간을 마음대로 해제 할 수 없다.
    return 0;
}