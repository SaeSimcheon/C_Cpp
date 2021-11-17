#include<iostream>
#include<string.h>
class string{
    char * name ;
    public:
    string(const char * pp){
        strcpy(name,pp);
        std::cout << name << std::endl;
    }
    int length(){
        return sizeof(name)-1;
    }
    string & add_string(const char * added){
        // 공간을 추가로 늘려서 해야할 것 같은데 어떻게 해야할까?
        
        return *this ;
    }  
};



int main(){
    string a("abs");
    std::cout << sizeof(char)<<std::endl;
    std::cout << sizeof("abs")<<std::endl;
    std::cout << a.length()<<std::endl;
    return 0;
}





/*
#include <iostream>

class string{
    public:
    string(const char * pp){
        std::cout << pp <<std::endl;
    }
};

int main(){
    char c[] = "abs";
    string a(c);
}
*/

/*
#include <iostream>

class string{
    public:
    //string(const char * pp){ 동일한 결과
    //string(const char pp[]){ 동일한 결과
    string(const char pp[4]){ // 동일한 결과
        std::cout << pp <<std::endl;
    }
    //string(char pp[4]){ //아래와 동일한 결과
    //string(char * pp){ //아래와 동일한 결과
    string(char pp[]){
        pp[0]='c';
        std::cout << pp <<std::endl;
    }
};

int main(){
    char a[] ="abs";
    char b[4] ="abs";

    std::cout << a <<std::endl;
    std::cout << b <<std::endl;

    string c("abs");
    string d(b);
    std::cout << b <<std::endl;
}
*/





/*  invalid conversion from 'const char*' to 'char' [-fpermissive]

#include <iostream>

class string{
    public :
    string(const char & pp ){
        std::cout << pp << std::endl;
    }
};

int main(){
    string s("abs");
    return 0 ;
}



*/





/*
#include<iostream>
class string{
    char * p;

    public:
    // string( char * pp){ forbid converting string constant to char * ;
    string(const char * pp){ // 이건 됨
    // char *인 경우에는 안에서 조작하는 논리 때문에 아마 안 되는듯 ? 
        std::cout << pp <<std::endl;
        std::cout << pp[0] <<std::endl;
        std::cout << pp[1] <<std::endl;
        std::cout << pp[2] <<std::endl;
        printf("%p",pp); 리터럴 그 자체와 주소 같음
        // 단순한 포인터로 받으면 값의 변경이 일어날 수 있기 때문에
        // 리터럴을 함수의 인자로 직접 주는 경우에는 일단 const char *로 가능

        // std::cout << pp[3] <<std::endl; 이건 그냥 공백이 나옴
        //std::cout << pp[4] <<std::endl; 이것도 일단 그냥 공백
        //p = pp;
    }
};

int main(){
    std::cout << &"abs" << std::endl;
    string a("abs");

}

*/


/* 이건 안 됨 저런 이유로
#include<iostream>

class string{
    char p[] ;//ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
    //error: no matching function for call to 'string::string(const char [4])'     string("abs");
    int size ;

    public:
    string(const char & pp){
        p=pp;
    }
};




int main(){

    string a("abs");


    return 0;
}
*/