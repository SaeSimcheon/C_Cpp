#include <iostream>

// 오버로딩 케이스를 확인할 수 있는만큼 확인해보자 !

using namespace std;

class A{
    int a ;
    public: // 생성자도 private에 들어갈 수 있다. 그렇게 되면 main 함수에서 
    // 쓰던대로 못 씀.

    A(){
        this ->a = 10;
    }
    A(int _a){
        this ->a = _a;
    }
    void print(){
        cout << this->a<<endl;
    }

};


int main(){
    A inst_A_1(30); 
    A inst_A_2; 
    inst_A_1.print();
    inst_A_2.print();
    


    return 0 ;
}