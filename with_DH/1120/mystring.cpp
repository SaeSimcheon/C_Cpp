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
    -> p_c. 필요한 메모리 크기가 현재까지 보유하고 있던 크기보다 크다면, 새로 할당 받아야하는데 그를 위해서는 임시로 포인터 하나를 새로 만들어 내용을 보관하고 사용한다.
    */
    
    
    /* 8. 리턴형에 대한 궁금증 mystring & return 이 &가 빠지면 오류가 남
    mystring & tmp = *this;
    mystring  tmp = *this;
    내부 멤버 변수에 실제로 무엇인가 반영이 되었더단가 한 경우에는
    그래야하는듯 -> 그런데 왜지?
    void return 형인 경우 또 가능함
    
    mystring ~ return *this 인 경우는 안 돼
    mystring& ~ return *this 이건 됨
    
    */
    
    mystring & addstring(const char * _added){
        int added_len = strlen(_added) ;
        
        if (size_mem > size + added_len){    
            for (int i =0 ; i < added_len; i ++){
                p[size+i] = _added[i];
            }
            size = size+added_len;
        }else{
            //7_p_c 필요한 메모리 크기가 현재까지 보유하고 있던 크기보다 크다면, 새로 할당 받아야하는데 그를 위해서는 임시로 포인터 하나를 새로 만들어 내용을 보관하고 사용한다.
            char * tmp =p;
            
            size_mem = 2*(size+added_len); // 새로 할당받기 위한 메모리 사이즈는 이와 같음
            p = new char[size_mem]; // p에 새로 할당 받음
            
            for (int i =0 ; i < size; i ++){
                p[i] = tmp[i];
            }
            for (int i =0 ; i < added_len; i ++){
                p[size+i] = _added[i];
            }
            delete[] tmp;
            size = size+added_len;
        }
        
        
        return *this;
    }
    /* 9. find : 문자열 검색
    > 문자열 첫 지점이 찾아지는 index 부터 substr의 길이만큼 탐색
    > 탐색해야하는 길이가 남은 길이보다 작으면 
    > 만약 다른 지점이 발생하면 false
    > 다른 지점을 찾지 못하고 종료되면 true
    */
    bool find(const char * substr){
        int substr_len = strlen(substr);
        for (int i =0 ; i < size ; i++){
            if (substr[0] == p[i]){
                if (size-i < substr_len){
                    return false;
                }else{
                    for (int j = i+1 ; j < substr_len ; j++){
                        if (substr[j]!=p[j]){
                            return false;}
                    }
                    return true ;
                }
            }
        }
        return false;
    }
    /* 10. 문자열이 같은지 확인하는 함수 same
    > 먼저 길이 기준으로 확인하고 길이가 다르면 return false
    > 길이가 같으면 끝까지 같은지 확인하고 만약 종료까지 다른 부분이 존재한다면 return false
    > 앞의 절차를 거쳐 마지막까지 진행된다면  return true
    */
    bool same(const char * str){
        if (size !=strlen(str))
            return false;
        for (int i =0; i < size ; i++){
            if (p[i]!=str[i])
                return false;
                
        }
        return true;
    }
    
    /* 11. 문자열 크기 비교
    */
    bool 
};


int main(){
    mystring ms("delicious");
    cout << ms.same("delicious") << endl;
    ms.print();
    ms.addstring("adsfasdfasdfasdfas");
    ms.print();
    ms.addstring("adsfasdfasdfasdfas");
    ms.print();
    cout << ms.find("ous") << endl;
    


    
    return 0;
}