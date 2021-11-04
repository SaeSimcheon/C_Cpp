#include <iostream>
#include <string>
using namespace std;

int main(){
    int a = 5;
    // int a; 동일한 범위에 같은 변수 이름을 두 번 정의 하면 오류가 발생한다.
    {
        a=6;
        int a; // 이건 가능 a#2가 선언 되면서 a#1은 숨겨짐 블럭이 닫힌 후 #1이 다시 보임
        a= 8;
        cout << a << endl;
    }
    // 불행하게도 숨기기는 바깥쪽 범위에 있는 같은 이름의 변수에 접근할 수 없게 만든다

    // 중첩과 접근성을 관리하는 더 나은 해결책은 바로 네임 스페이스이다.
    cout << a << endl;
}


