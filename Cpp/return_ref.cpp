// 당연히 됨



#include<iostream>
/*
int& function(){
    int a = 2;
    return a;
} // return_ref.cpp:9:12: warning: reference to local variable ‘a’ returned [-Wreturn-local-addr]
// 로컬 변수의 레퍼런스가 반환된다?
// a 는 로컬 변수
// a는 함수 종료와 함께 사라짐.

// int& ref = a; a가 사라짐
// int b = ref; 와 같은 문장
*/

/*
int function(){
    int a = 2;
    return a;
}
*/

// 여기서 &가 있으나 없으나 가능함
int& function(int& a){
    a =5;
    return a;
}


int main(){
    int b =2;
    int c = function(b);
    std::cout << b <<std::endl;
    
    return 0 ;
}