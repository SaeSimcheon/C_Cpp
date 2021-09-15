#include <iostream>

using namespace std;

template <class T>
    
void print(T array [] , int n ){
    for (int i = 0 ; i < n ; i ++)
        cout << array[i] << '\t';
    cout <<endl ;
}


void print(char array [],int n){
    for (int i = 0 ; i < n ; i ++)
        cout <<(int)array[i] << '\t';
    cout <<endl;
}


int main(){
    int x[] = {1,2,3,4,5};
    double d[5] = {1.1,2.2,3.3,4.4,5.5};
    print(x,5);
    print(d,5);
    
    char c[5] = {1,2,3,4,5};
    print(c,5);
}


// 1,2,3,4,5에 매칭되는 아스키 코드가 없기 때문에 빈 공백만 출력됨
// 해결