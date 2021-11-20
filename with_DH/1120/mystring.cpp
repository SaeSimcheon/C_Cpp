/* 계
*/

#include<iostream>

using namespace std;
class mystring{
    
    int size =0; 
    char * p ;   
    /*3. 메모리 동적할당 받는 방법? 
    char * p = new char[size]; 이렇게 두고 int를 초기화를 안 하니까 에러가 나와서 다른 방법을 찾아야겠다고 생각함.
    => 이렇게 포인터로 먼저 실행해두고 아래 생성자에서 동적으로 새로 할당 받으면 사이즈 문제 해결 된다고 생각
    
    생성자 ... {
    p =  new char[10];
    }
    
    */
    public :
    /*
         1.인자는 어떤 형태가 적절한가? mystring(const char s[]) 
           mystring(const char s[10] ) const char * 로 변환 됨
    */
    mystring(const char * s ){     
        /* 2. string size를 알고 싶음
         이 두 개는 왜 사이즈가 다를까? = > 정답은 s는 포인터라서 포인터 사이즈를 출력한 것임. 
         포인터가 가리키는 것의 사이즈를 알고 싶으면 *s인데 s는 리터럴의 첫번째 원소의 포인터라서 char의 크기인 1이 나옴
         cout << sizeof(s) << endl;
         cout << sizeof("hello") << endl;
        */
        /*
         4. for문을 통한 사이즈 찾기
         for 문을 조건 없이 돌려서 
        */
        for (int i = 0;;i++){
            if (s[i] =='\0') break;
            size++;
        }
        
        p =  new char[size];
        
        
        
    }
    
    ~mystring(){// 소멸자는 인자를 받지 않는다
        delete[] p;
    }
};


int main(){
    mystring ms("hello");
    return 0;
}