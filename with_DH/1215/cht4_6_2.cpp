#include <iostream>

//mutable 키워드를 통해서 const 함수 안에서도 변수 값을 변화시킬 수 있다.

// 왜 쓰는 걸까? -> 예를 들면 데이터베이스 읽기를 하는데 오래 걸리는 작업이라서 캐시를 이용. 캐시는 변화를 줘야하는 반면, 데이터 베이스 자체는 변화를 주지 않기 때문에
// mutable을 둔 변수는 제한 없이 변화가 가능하다. 
// 특정 const 함수 안에서 반드시 변화시켜야 할 것들이 존재하는데, const의 이점을 함께 취할 수 있다.
class A{
    mutable int data_;

    public :
    A(int data): data_(data){}
    void DoSomething(int x ) const{
        data_ = x; 
    }

    void printdata() const { std::cout << "data : " << data_ << std::endl;}

};

int main(){
    A a(10);
    a.DoSomething(3);
    a.printdata();
}
