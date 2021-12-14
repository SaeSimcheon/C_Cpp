#include <iostream>


using namespace std;
void print(int x ){ cout << "int " << x << endl;}
//void print(char x ){ cout << "char " << x << endl;}
void print(double x ){ cout << "double " << x << endl;}

int main(){
    print(5);
    print('a'); // char의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에 
    // '자신과 최대로 근접한 함수를 찾게됨'
    /*
    int 5
    int 97
    double 4.2
    이렇게 나옴

    */
    print(4.2); // 뒤에 f 붙여주는 것은 float임을 알려줌.

    return 0 ;
}