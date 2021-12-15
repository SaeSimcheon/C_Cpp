/*
구현 해보기 

문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성

문자열 길이를 구하는 함수

문자열 뒤에 다른 문자열 붙이기

문자열 내에 포함되어 있는 문자열 구하기

문자열이 같은지 비교

문자열 크기 비교 (사전 순)
*/


#include <iostream>

// 문자열을 관리하는 class
// 일단 리터럴이나 문자를 받아서 관리하고 
// 문자열 자체도 받는다.
// 문자열의 길이와 확보한 메모리도 갖고 있자.
using namespace std;
class String{

    const char * a;

    int length;
    int mem ;

    public:
    // character 받는 생성자
    // _a는 문자 리터럴
    int get_size(const char * given){
        int size = 0 ;

        for (;;){
            if (given[size]!='\0')
                size+=1;
            else
                break;
        }
        return size;

    }
    String(const char _a)
    :a(_a),length(1),mem(1)
    {}

    String(const char & _a){

        //a = _a;// 이대로면 새로 문자열을 할당하거나 뒤에 문자열을 붙이는 등의 작업을 할때 문제가 있을 것 같음. _a는 리터럴 문자열을 가리키고 a로 같은 곳을 가리킨다는 의미가 되기 때문
        //length = get_size(a);
        //cout << a << endl;
        cout << _a << endl;
    }
};


int main(){
    char ss[3] = {'a','b','\0'};
    int ints[3] = {1,2,3};
    // 문자 배열
    // 
    //char * & sss = ss; 이런 표현 불가능
    String str1('a');
    //String str2(ss);

    return 0 ;
}

// 인자로 문자배열을 받을때 char * a <- char a[] , char a[10] 같게됨
// 문자배열을 받을때 const char * a 나 char *a나 변화만 시키지 않는다면 
// 문자열 리터럴을 인자로 받을때 const char * a 이렇게 받아야함.(문자열 리터럴의 주소를 저장) const char & (주소의 별명은 불가) 이건 가능한가? 이건 불가능함.
