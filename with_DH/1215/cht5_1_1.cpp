// 사용자 정의 연산자 사용 가능.
//:: . .*를 제외하고 가능.
//연산자 오버로딩.
// (리털 타입) operator(연산자) (연산자가 받는 인자)

// bool operator==(mystring& str)

// str1 == str2 라는 명령을 한다면 str1.operator==(str2)로 내부적으로 변환돼서 처리 됨.
//
#include<iostream>


using namespace std;
class complex {
    double real,img;
    
    public: 
    complex(double real,double img):real(real),img(img){}
    complex(const complex& c){real = c.real,img = c.img;}
    
    complex operator+(const complex& c) const ;
    complex operator-(const complex& c) const ;
    complex& operator=(const complex & c);
    void print(){cout <<"real : "<< real <<" img : " << img <<endl;}
};

complex complex::operator+(const complex & c) const {
    complex temp(real + c.real, img + c.img);
    return temp;
}

complex complex::operator-(const complex &c ) const {
    complex temp(real -c.real, img -c.img);
    return temp;
}

complex& complex::operator=(const complex & c){
    real = c.real ;
    img = c.img ;
    return *this;
}

// complex &가 아니라 complex를 리턴 타입으로 갖는 이유?
// Complex a = b + c + b; 이런 식에서 
// 뒤의 b에 순서대로 연산한 b+c에 의해 b+c 의 결과가 반영되기 때문
// 참조자 리턴 -> 임시저장소에 복사 없음.
int main(){
    
    complex a(1.0,2.0);
    complex b(3.0,-2.0);
    
    complex c = a +b;
    complex d = a -b;
    c.print();
    d.print();
    
    c=b=a;
    a.print();
    b.print();
    c.print();
    
    return 0; 
}