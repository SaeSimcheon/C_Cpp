#include <iostream>

// 오버로딩 케이스를 확인할 수 있는만큼 확인해보자 !

using namespace std;
void print(int x ){ cout << "int " << x << endl;}
//void print(char x ){ cout << "char " << x << endl;}
//void print(double x ){ cout << "double " << x << endl;}

// enum이란 ? 열거형. 메모리 낭비를 하지 않음

// enum {RED,BLUE,WHITE,BLACK} 순서대로 0부터임. 별다른 설정 없으면
// enum {RED=3,BLUE,WHITE,BLACK} 이렇게 시작 설정도 가능 3 4 5 6 
// enum {RED=3,BLUE,WHITE=3,BLACK} 이렇게하면 3, 4 이고 다시 WHITE에서 3이고 BLACK 4가 됨
// 열거형은 항상 정수여야함.
enum {RED,BLUE,WHITE,BLACK};

int main(){
    short short_test = 6;
    // unsigned char = 'b'; 이거 아니라는데?
    char char_test = 'a';
    float float_test = 4.2f;
    print(short_test);
    print(char_test);
    
    
    print(float_test);
    // float의 경우 double이 없는 경우에 int로 형변환하여 일치하는 함수를 찾음.
    // 오버로딩 기준 3단계 임의의 숫자 타입은 다른 숫자 타입으로 변환하게 함.


    // 만약에 int 함수를 없애고 double만 남기면 숫자로 넘어갈 수 있는 것들은
    // 전부 double로 형변환하여 일치하는 함수를 찾게 됨.
    // enum도 예외 아님.

    // float -> double 매칭이 안되면 2단계는 생략하고 3단계로 오버로딩 하려고 하는데
    // 임의의 숫자형으로 형변환을 시도함. char도 int도 모두 후보가 될 수 있으므로 
    // 두 개 이상의 가능한 일치가 존재하므로 오류가 발생함.

    // cht4_1_2.cpp:27:21: error: call of overloaded 'print(float&)' is ambiguous


    print(RED); // 열거형 또한 int로 
    
    

    return 0 ;
}