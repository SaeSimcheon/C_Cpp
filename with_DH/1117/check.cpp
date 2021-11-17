#include<iostream>

class A{
    public:
    A(){
        std::cout << "hello" << std::endl;
    }
    
    A(const A & aaa){
        std::cout << "복사생성자" <<std::endl;
    }

    A(int a){
        std::cout << "hello "<<a << std::endl;
    }
};

int main(){
    //A aa = 10; //explicit 들어가는 순간 얘는 안 돼 // 없으면 가능해 -> 이렇게 되면 함수 인자에서 내가 설정하지 않았지만, 암시적인 변환이 일어나는 것을 막아 줌
    A bb = A(10); // 얘는 explicit 들어와도 괜춚
    A ccc = bb;// 얘네가
    A ddd(bb);// 복사생성자
    // 즉, explicit은 A aa = 10;을 막음
    return 0;
}