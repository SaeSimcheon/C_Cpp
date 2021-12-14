#include <iostream>

// 오버로딩 케이스를 확인할 수 있는만큼 확인해보자 !

using namespace std;

class A{
    int a ;
    public: // 생성자도 private에 들어갈 수 있다. 그렇게 되면 main 함수에서 
    // 쓰던대로 못 씀.

    A(int _a){
        this ->a = _a;
    }
    void print(){
        cout << this->a<<endl;
    }

};

class AA{
    int a =5;

    public :
    AA() = default ; // 명시적인 디폴트 생성자 사용. 
    // default 생성자를 위해서 일부러 생성자를 정의 안 한 것인지
    // 실수인지 구분이 안 되기 때문에 명시적으로 사용하는 것이 좋다.
    void print(){
        cout << a << endl;
    }
};


int main(){
    A inst_A_1(10); // implicit : 함수를 호출하듯 한다는 점에서 암시적.
    A inst_A_2 = A(10); // explicit : 생성자를 명시적으로 호출한다는 점. A() -> 생성자
    // 정의한 생성자를 직접적으로 표현한다는 점에 주목하자.

    //A default_A ; // 어떤 다른 생성자를 추가한 순간 디폴트 생성자를 삽입하지 않는다.
    AA default_AA; // 디폴트 생성자 사용.
    default_AA.print();
    
    
    /*
    AA default_AAA();
    default_AAA.print();
    cht4_1_3.cpp:40:17: error: request for member 'print' in 'default_AAA', which is of non-class type 'AA()'
    40 |     default_AAA.print();
      |      
    // 명심해야할 것은 디폴트 생성자를 사용할때 앞처럼 A inst() ; 이런식으로 사용하면 안 됨.
    // 리턴 값이 AA 이고 inst라는 이름을 가진 인자 없는 함수를 정의하는 것으로 인식함.
    // 명시적표현은 가능. 암시적 표현은 불가능.
    // 이렇게 암기하자.
    */




    inst_A_1.print();
    inst_A_2.print();


    return 0 ;
}