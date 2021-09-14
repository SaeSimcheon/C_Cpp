#include <iostream>

#include <string.h>


class MyString{
    char* string_content ;
    int string_length ;
    
    public:
    MyString(char c );

    MyString(const char * str);

    MyString(const MyString& str);
    
    ~MyString();
    int length() const;
    
    void print() const;
    void println() const;
};



MyString::MyString(char c ){ // 한 문자 생성자
    string_content = new char[1];
    string_content[0] = c;
    string_length =1 ;
}


MyString::MyString(const char* str){ // 문자열 생성자
    string_length = strlen(str);
    string_content = new char[string_length];
    
    
    for (int  i = 0 ; i != string_length; i ++ ) string_content[i] = str[i];
}

MyString::MyString(const MyString& str){ // 복제 생성자
    string_length = str.string_length ;
    string_content = new char[string_length];
    
    for ( int i = 0 ; i != string_length ; i ++)
        string_content[i] = str.string_content[i];
}

MyString::~MyString(){delete[] string_content;}

int MyString::length() const {return string_length ; }
void MyString::print() const{
    for (int i = 0 ; i != string_length ; i ++){
        std::cout << string_content[i];
    }
}

void MyString::println() const{
    for (int i = 0 ; i != string_length ; i ++){
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}







int main(){
    MyString str1("Hello");
    MyString str2(str1);
    
    
    str1.println() ; 
    str2.println() ; 
}