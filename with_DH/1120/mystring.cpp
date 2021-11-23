/* 계
*/

#include<iostream>
#include<cstring>
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
    int size_mem =0; // 7_p_a
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
         for 문을 조건 없이 돌려서 null 문자인 '\0'을 만나는 시점까지 size올려줌
         for (int i = 0;;i++){
            if (s[i] =='\0') break;
            size++;
        }
        */
        /* 
        8. 사이즈 구하는 방법 반복문 말고 sizeof 이용하는 방법
        -> cstring의 strlen이라는 함수를 사용하는 방법이 있음
        -> 아니면 반복문으로 해야할듯
        */
        //cout << sizeof()<<endl;
        //cout << strlen(s)<< endl;
        //cout << sizeof("delicious")<< endl;
        
        size = strlen(s);
        size_mem = 2*size; // 7_p_a
        
        
        
        p =  new char[size_mem];
        /* 5. size만큼 반복문을 수행하여
        새로 동적으로 할당받은 영역에 입력
        */
        for (int i = 0;i < size;i++){
            p[i] = s[i];
        }
    }
    
    ~mystring(){// 소멸자는 인자를 받지 않는다
        delete[] p;
    }
    /* 6. print라는 출력함수 생성
    */
    void print(){
        cout << p << endl;
    }
    
    
    /* 7. 뒤에 문자열을 추가하는 함수 addstring 
    -> p_a. 있는 것 뒤에 새로 메모리를 할당 받아야한다? -> 이런 방식 말고, 애초에 메모리 변화가 있을때마다 현재의 2배를 할당해두고 사용
    -> p_b. 할당 받은 메모리 크기를 미리 저장해두자. -> size_mem이라는 변수 따로 만들어두기로 함 
    */
    
    mystring & addstring(const char * _added){
        int added_len = strlen(_added);
        
        if (size_mem > size + added_len){    
            for (int i =0 ; i < added_len; i ++){
                p[size+i] = _added[i];
            }
            size = size+added_len;
        }else{
            
            
            char * tmp =new char[size_mem];
            
            delete[] p; // p 에 할당된 메모리 해제
            size_mem = 2*(size+added_len); // 새로 할당받기 위한 메모리 사이즈는 이와 같음
            p = new char[size_mem]; // p에 새로 할당 받음
            
            for (int i =0 ; i < added_len; i ++){
                p[size+i] = _added[i];
            }
            
            
            
        }
        
        
        return *this;
    }
};


int main(){
    mystring ms("delicious");
    ms.print();

    
    char * a ;
    char * b ;
    // 7. addstring에서 임시로 동적메모리를 보관하고 싶은데 방법이 있을까?
    // 다음 시도는 pointer 2개를 만들어서 한 쪽에(a에) 동적으로 할당 받은 것을 다른 포인터가 가리키게 하고
    // 해제 하지 않고, a에 새로 할당하는 방법
    // 됨 . 따라서 임시포인터 만들어서 가리키게 한 다음 사용하는 방법도 유효하다고 생각한다.
    a = new char[10];
    a[0]='a';
    a[1]='b';
    a[2]='b';
    cout << "a " << a << endl;
    cout << "b " << b << endl;
    b = a;
    cout << "a " << a << endl;
    cout << "b " << b << endl;
    a = new char[20];
    
    a[0]='c';
    a[1]='c';
    a[2]='c';
    a[3]='c';
    cout << "a " << a << endl;
    cout << "b " << b << endl;
    
    delete[]a;
    delete[]b;
    return 0;
}