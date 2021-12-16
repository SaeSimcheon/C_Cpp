// 문자열을 complex 수와 덧셈 해보자.
// 개별 연산자마다 정의하는 방법도 있지만, 생성자를 만드는 쪽이 훨씬 편하다.
// 13:47 문자열을 받는 생성자 만들기

// 원래 논리는 complex + "any string" -> 이렇게 연산을 시도 했을때 
// 오버로딩된 연산자 + 에 의해서 const char *을 인자로 받는 함수가 적용되어 내부에서 const char * -> complex로 변환한 후에 연산이 이루어짐.
// 하지만, const char *을 받는 함수가 없어도 생성자만 정의해도 연산이 됨.


// 생성자에 의한 암시적인 형변환이 이루어질 수 있다는 점을 염두하고 짤 수 있음.



// a = a + "-1.1 + i3.923"; -> a = a.operator+("-1.1 + i3.923"); -> a = a.operator+(Complex("-1.1 + i3.923")); 이렇게 됨.
// 



#include<iostream>


using namespace std;
class complex {
    double real,img;
    
    public: 
    complex(double real,double img):real(real),img(img){}
    complex(const char * c);
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


complex::complex(const char * c){
    int size = 0;
    int indicator = -1;
    for (;;){
        if(c[size]=='\0')
            break;
        size++;
    }

    for (int i =0 ; i < size ; i ++){
        if(c[i]=='+'){
            indicator = i;
            break;
        }
    }
    if(indicator != -1){
        char * ch1 ;
        char * ch2 ;
        
        real = stod();
        img = stod(c[indicator+1]);
    }
}


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


complex& complex::operator=(const complex & c){
    real = c.real ;
    img = c.img ;
    return *this;
}

// char ch2[]; 문자열 배열은 size 정해줘야함. 사이즈 정해주지 않으면 얼마만큼 확보를 해둬야 할지 모르니까 안 되는듯


int main(){
    
    complex a(1.0,2.0);
    complex b(3.0,-2.0);
    b.print();
    complex c =b=a;
    b.print();
    c.print();
     

    
    return 0; 
}