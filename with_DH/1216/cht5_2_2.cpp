#include <iostream>
// a = a + "-1.1 +i3.923"; 
// a = "-1.1 + i3.923" + a; -> 컴파일 안 됨.

// 컴파일러는 이항 연산자를 다음 두 개의 방식으로 해석함.

// a@b -> a.operator@(b); // operator@(a,b)
// 전자는 클래스의 멤버로 사용. 후자는 클래스 외부의 일반적인 함수

// [] -> = ()는 멤버 함수로만 존재할 수 있음. -> 오버로딩할 경우 유의할 것.

// a가 클래스가 아니면 첫번째는 해당이 안 되니까 넘어가겠지 ?
// private 멤버 변수에 접근해야할 필요가 있으므로 friend를 선언해줌.
// a = a+a의 경우 a.operator+(a)와 operator+(a,a) 
// 모두 사용할 수 있기 때문에 에러가 남

// 통상적으로 자기자신을 리턴하지 않는 이항연산자들은 모두 외부 함수로 선언하는 것이 원칙임.




// 입출력 연산자 오버로딩


/*
ostream & operator <<(ostream& os, const complex & c){
os << "( " << c.real << " , " << c.img << " ) ";
return os;
}

ostream 객체를 인풋으로, << 오버로딩 // 
ostream &을 리턴해야함.

즉 , ostream & -> os 외부의 ostream 객체와 연결시켜서 리턴시에 그 자리에 남게함. -> 수정된 객체를 통하여 연속적인 구문 사용 가능.

*/


// 첨자 연산자 operator[]

// 배열의 원소를 지정할때 [] 안에 넣는 수를 첨자라고 부르기 때문 
// 래퍼런스를 리턴하는 이유는 str[10] = 'c' 이런식으로 명령을 수행할 수 있기 위해서 
// str[10] 자리에 해당 메모리 위치가 반환되어서 'c'로 대체될 수 있도록 함.





// int wrapper class 무언가를 포장하는 클래스
// 기본 자료형을 객체로 다루어야할 때가 있음.
// int 자료형을 감싸는 클래스느 int Wrapper class


class Int{
    int data;
    
    public :
    Int(int data) : data(data){}
    Int(const Int & i ):data(i.data){}
    
    operator int() { return data;}
};

// int와 아주 동일하게 연산이 가능하게 하고 싶은데
// 일일이 연산자들에 대해서 오버로딩 해주는 것이 여간 귀찮은 것이 아님.
// wrapper를 마치 int 형 변수라고 컴파일러가 생각할 수 있게 만드는 방법
// 타입 변환 연산자가 있기 때문
// operator (변환 하고자 하는 타입)
// operator int(){ return data;}
// 생성자처럼 리턴타입 쓰면 안 됨.
//

int main(){
    
    Int x = 3;
    int a = x +4;
    std::cout <<x <<std::endl;
    std::cout <<a <<std::endl;
}