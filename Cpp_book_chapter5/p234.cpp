#include <iostream>
using namespace std;

int main(){
    cout << "i" << '\t' << "n" << '\t' <<"refn" <<endl;
    int i = 1;
    int n = 2;

    int &refn = n;
    int &refe = refn; // 참조변수에 대한 참조 선언이 가능하다. 
    n = 4 ;
    refn++;
    cout << i << "address of n " << &n <<endl;
    cout << i << "address of refn " << &refn <<endl; // 참조자의 주소는 따로 존재하지 않고 원본 변수의 주소를 호출하는 것과 같다.
    cout << i << '\t' << n << '\t' << refn <<endl;
    cout << i << '\t' << n << "\t\t" << refe <<endl; // 이때 참조 변수에 대한 참조가 아니라, 원본 변수에 대한 참조가 된다.

    refn =i ;
    refn ++ ;
    cout << i << '\t' << n << '\t' << refn <<endl;
    cout << i << '\t' << n << "\t\t" << refe <<endl; 

    int *p = &refn ; // p는 n의 포인터 변수
    cout << "p "<<p << endl;
    cout << "&n "<<&n << endl;
    
    *p = 20;
    cout << i << '\t' << n << '\t' << refn << endl;

}

