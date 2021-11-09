#include <iostream>
#include <string>
using namespace std;

void print(const int & x ){
    cout << x << endl;
}
//void print(const float & x ){
//    cout << x << endl;
//}

//void print(const char & x ){
//    cout << x << endl;
//} 모호함!

void print(const string & x ){
    cout << x << endl;
}

int main() {

    int a = 10;
    float b = 1.5f;
    string c = "hello";

    print(a);
    print(b);
    print(c);

    return 0;
}