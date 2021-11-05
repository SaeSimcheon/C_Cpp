#include <iostream>

int main(){
    // int &a = 10;
    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // const reference 아니면 리터럴은 못 받아
    const int &a = 10;
    // 이건 돼 바꾸는 기능을 제거한다면 허용해줄게
    std::cout << a << std::endl;
}