#include <iostream>

int main(){
    int * list = new int[10];
    std::cout << "list는 포인터다 " <<list << std::endl;
    std::cout << "p는 누구를 가리켜? " <<*list << std::endl;
    
    std::cout << "list[0]는 무엇일까  " <<list[0] << std::endl;
    std::cout << "list[9]는 무엇일까  " <<list[9] << std::endl;
    std::cout << "list[10]는 무엇일까  " <<list[10] << std::endl;
    // T * pointer = new T[size];
    delete[] list;
    // 배열의 delte는 delete[] list; 의 형태로 수행된다.
    
    return 0;
}