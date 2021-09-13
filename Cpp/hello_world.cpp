#include <iostream>

int main(){
    //std::cout <<"hello" << std::end|; 안 됨
    //std::cout <<"hello" << std::end; 안 됨
    //std::cout <<"hello" << std::endl;
    // std::cout <<"hello" ; 됨 std:endl이 없으니 예전에 printf에서 \n 안 한거랑 같음
    std::cout <<"hello" << std::endl;
    return 0;
}