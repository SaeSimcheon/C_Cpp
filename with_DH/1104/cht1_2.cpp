#include <iostream>

using namespace std;

int main(){
    int i1 =2;

    int i2,i3 =5;
    // i2는 확인할때마다 값이 다름
    float pi = 3.123456789234124f;
    //3.12346 -> 자동으로 캐스팅됨 ; double로
    double dpi = 3.123456789234124;
    //3.12346
    long double ldpi = 3.123456789234124l;
    long double hd = 3.123456789234124l;
    
    // 왜인지 모르겠는데 자동으로 캐스팅 됨
    cout.precision(19);

    // cout의 precision이라는 멤버함수를 통해서 수정해야함
    char cc = 37;
    char c1 = 'a',c2 =35;

    bool tt = true;

    const char* a = "abc";

    cout<<a[0] <<endl;
    cout<<a[1] <<endl;
    cout<<a[2] <<endl;
    cout<<a[3] <<endl;
    printf("%p\n",a);
    printf("%p\n","abc");
    cout << &"abc" <<endl;


    //cout << a <<endl;
    cout << &a <<endl;
    cout << *"a" <<endl;



    cout << tt <<endl;
    cout << tt +1 <<endl;
    cout << i1 <<endl;
    cout << i2 <<endl;
    cout << i3 <<endl;
    cout << pi <<endl;
    cout << dpi <<endl;
    cout << ldpi <<endl;
    cout << hd <<endl;
    cout << cc <<endl;
    cout << c1 <<endl;
    cout << c2 <<endl;

    return 0;
}