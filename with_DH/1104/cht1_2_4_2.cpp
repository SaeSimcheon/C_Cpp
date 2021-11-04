#include <iostream>
#include <string>
using namespace std;

int main(){
    const double pi = 3.1234567898;
/*
    {
        const double pi = 3.1234567898; // 오류 발생 지역 변수의 가시성 가용성은 함수 선업부의 {}로 둘러싸인 블록으로 제한한다.
    }
*/
    cout << pi << endl;
}


