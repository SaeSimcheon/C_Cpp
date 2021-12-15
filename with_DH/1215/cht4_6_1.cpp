#include <iostream>

// 컴파일러는 만약 특정 함수에 정의되지 않은 인자가 들어오는 경우 생성자를 통해서 암시적 변환을 하는 경우 있음.
// 예상하지 못한 변환이 일어날 수 있음.

// int를 받는 생성자에 explicit 즉, 명시적이라는 키워드를 넣음으로써 암시적인 변환을 막을 수 있음.

// 또한 복사 생성자의 형태로도 호출되는 것을 막음.


// 암시적인 복사생성자도 있음.
// mystring s = 5 ; 이런식으로 


class mystring{
    char * string_content ;
    int string_length ;
    int mem;

    public :

    // explicit mystring(int capacity);
    mystring(int capacity);
    mystring(const char * str);
    mystring(const mystring & str);

    ~mystring();

    int length() const;
};

void DoSomethingWithString(mystring s) {
    std::cout << "Do" << std::endl;
}

mystring::mystring(int capacity){
    string_content = new char[capacity];
    string_length = 0 ;
    mem = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

mystring::mystring(const char * str){
    string_length = 0 ;
    while(str[string_length++]){}

    string_content = new char[string_length];
    mem = string_length;

    for (int i = 0 ; i !=string_length ; i ++ ) string_content[i] = str[i];

}

mystring::mystring(const mystring& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for(int i =0 ; i !=string_length ; i ++)
        string_content[i] = str.string_content[i] ;
}

mystring::~mystring(){ delete[] string_content;}

int mystring::length() const { return string_length;}

int main(){ DoSomethingWithString(3);
mystring s = 3;}

