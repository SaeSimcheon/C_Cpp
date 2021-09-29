#include <iostream>

char & find(char& u);
//char & find(char k);


int main(){
    char c ='a';
    
    char a =find(c);
    std::cout << c <<' '<< a << std::endl;
    find(c) = 'b';
    char&ref = find(c);
    std::cout << c <<' '<< a <<' '<< ref << std::endl;

    ref = 'k';
    std::cout << c <<' '<< a <<' '<< ref << std::endl;
    return 0;
}
/*
char & find(char k){
    char u = k;
    return u;
};
*/// 에러나는 이유  reference to local variable 'u' returned local variable에 대한 참조변수를 리턴한 경우 함수 실행 종료시에 스택이 사라지므로 참조변수만 남고 원본이 삭제 되므로
// 안 됨.

char & find(char &u){
    return u;
};