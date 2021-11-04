#include <iostream>
#include <string>
using namespace std;

int main(){
    int i = 3;
    cout << i <<endl;
    i ++; // 증감 연산자는 변수의 값만 변하고 임시 결과의 값은 변경하지 않는다.
    cout << i <<endl;

    const int j =5;
    // j++;오류
    // (3+5)++;
    /*
    cht1_3.cpp:13:7: error: increment of read-only location '(3 + 5)'
   13 |     (3+5)++;
      |     ~~^~~
    cht1_3.cpp:13:10: error: lvalue required as increment operand
    */
    // 증가 및 감소 연산은 수정 가능하고 주소를 지정할 수 있는 무언가가 피룡한다.
    // 주소를 지정할 수 있는 항목을 lvalue라고 한다.

    int k =3, kk =3;
    cout <<k<<' '<<kk <<endl;
    int m = ++k +4;
    int l = kk++ +4;
    // 전위는 수정 전 후위는 수정 후
    // 더불어 전위 후위 증감이 된 변수 또한 연산이 반영 된 것을 알 수 있다. (둘다 4)
    cout <<m<<' '<<l <<endl;
    cout <<k<<' '<<kk <<endl;

    int bj = -i;
    cout <<bj <<endl;
    // 전위와 함께 + - 단항 연산자 역시 같은 순위를 갖는다.
}


