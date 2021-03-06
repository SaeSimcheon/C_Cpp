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
    complex operator*(const complex& c) const ;
    complex operator/(const complex& c) const ;
    complex& operator=(const complex & c);

    complex& operator+=(const complex&c);
    complex& operator-=(const complex&c);
    complex& operator*=(const complex&c);
    complex& operator/=(const complex&c);

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
// (a+bi)(c+di)
complex complex::operator*(const complex &c ) const {
    complex temp(real*c.real-img*c.img, real*c.img+c.real*img);
    return temp;
}
//(a+bi)(c-di) /(c^2 +b^2)
complex complex::operator/(const complex &c ) const {
    double this_real_num = real*c.real + img*c.img;
    double this_img_num = - real*c.img + c.real*img;
    double denom = c.img*c.img + c.real*c.real;

    complex temp(this_real_num/denom,this_img_num/denom);
    return temp;
}

// 아래 연산자들도 개별적으로 정의 해주어야함.

complex& complex::operator+=(const complex& c){
    *this = *this+c;
    return *this;
}
complex& complex::operator-=(const complex& c){
    *this = *this-c;
    return *this;
}
complex& complex::operator*=(const complex& c){
    *this = *this*c;
    return *this;
}
complex& complex::operator/=(const complex& c){
    *this = *this/c;
    return *this;
}





// & 참조자리턴이 아니라 *this로 반환하는 것이 중요 하기 자신으로 반환해야

/*

void complex::operator=(const complex & c){
    real = c.real ;
    img = c.img ;
    //return *this;
}

b=a;
연산자에 의해 b의 내용 자체는 그냥 바뀌는 것이기 대문에 저렇게 정의해도 상관 없음 다만,

complex c =b=a;

cht5_1_1.cpp: In function 'int main()':
cht5_1_1.cpp:89:17: error: conversion from 'void' to non-scalar type 'complex' requested
   89 |     complex c =b=a;
      |                ~^~

      이런 경우에 저 자리에 리턴 타입이 없으므로 오류가 남.

*/



complex& complex::operator=(const complex & c){
    real = c.real ;
    img = c.img ;
    return *this;
}



// complex &가 아니라 complex를 리턴 타입으로 갖는 이유?
// Complex a = b + c + b; 이런 식에서 
// 뒤의 b에 순서대로 연산한 b+c에 의해 b+c 의 결과가 반영되기 때문
// 참조자 리턴 -> 임시저장소에 복사 없음.

// operator=를 만들지 않아도 작동하는데 그 이유는 컴파일러 차원에서 디폴트 대입연산자를 지원하고 있기 때문 다만, 얕은 복사를 수행하기 때문에 깊은 복사는 따로 만들어 주어야함.



int main(){
    
    complex a(1.0,2.0);
    complex b(3.0,-2.0);
    b.print();
    complex c =b=a;
    b.print();
    c.print();

    
    

    
    return 0; 
}