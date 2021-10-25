#include <iostream>
using namespace std;


class Circle{public:
int k = 2;};

int main(){
    int n =2 ;
    int &refn = n;
    int &refnn = refn;// 참조 변수에 대한 참조를 수행하는 경우, 원본 변수에 대한 또다른 참조 변수가 생성됨.
    cout << " refn " << refn << endl;
    refn = 3;
    int *p = &refn;
    cout << " refn " << refn << endl;
    cout << " p " << p << endl;
    cout << " *p " << *p << endl;

    cout << " refnn " << refnn << endl;

    Circle c ;
    Circle &refc = c;
    cout << " refc.k " << refc.k << endl;
    return 0;
}

