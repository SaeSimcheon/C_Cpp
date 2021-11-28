/*
1125 피드백

- mystring을 인자로 받아서 복사 생성자 -> 깊은 복사를 하기 위함
- 그냥 char 하나만 받는 경우도 따로 두었음.
- 길이를 파악하는데에 나와 마찬가지로 strlen을 사용
* char 포인터 =new char[길이]

- 궁금한게 복사 생성자로 받은 인스턴스의 멤버 변수는 그냥 접근할 수 있나 ?
 -> 됨 !

 - assign 함수를 새로 추가 -> 확보하고 있는 메모리 크기와 새로 할당할
 문자열의 길이를 비교했을때 만약 작거나 같다면 그냥 덮어쓰게됨
 -> 문제는 내가 기존에 짰던 print가 cout 으로 그냥 출력하는 것이라서
 null 문제만을 고려하여 종료 반면에 교재는 해당 문자열의 길이만큼만 반복

 -동적으로 메모리가 할당된 포인터의 경우 delete를 통하여 해제해도
 포인터 자체가 사라지지 않는다는 점을 기억하기.



 - 나는 뒤에 문자열을 그냥 추가하는 함수를 만들었는데
 교재는 넣고 싶은 위치의 index까지 받는 함수를 만들었네

 - erase function 추가

 - find 함수에서 mystring 및 문자열 리터럴을 한 함수에서 해결할 수 있도록
 mystring을 인자로 받는 함수를 만들고 그 함수를 내부에서 호출하는 
 문자열 리터럴을 인자로 받는 함수를 오버로딩함.
-> 1129일 기준으로 세그먼테이션 오류가 일어남


- same compare 비슷한 기능을 가진 함수 굳이 필요 없어보임
*/


#include<iostream>
#include<cstring>
using namespace std;
class mystring{
    
    int size =0; 
    char * p ;   
    int size_mem =0; // 7_p_a
    public :
    mystring(const char * s ){     
        
        size = strlen(s);
        size_mem = 2*size; // 7_p_a
        
        
        
        p =  new char[size_mem];
        for (int i = 0;i < size;i++){
            p[i] = s[i];
        }
    }
    mystring(const mystring & str){
        size =str.size;
        size_mem = 2*size;
        p = new char[size_mem];

        for (int i = 0 ; i < size;i++){
            cout << str.p[i]<<endl;
            p[i]=str.p[i];
        }

    }

    ~mystring(){// 소멸자는 인자를 받지 않는다
        delete[] p;
    }
    void print() const {

        for (int i =0; i < size ; i++)
            cout << p[i] ;
        cout << endl;
    }
    mystring& assign(const mystring & str){
        if (str.size > size_mem){
            delete[] p;
            size_mem = 2*str.size;

            p = new char[size_mem];
        }
        for (int i = 0 ; i < str.size ; i ++){
                p[i] = str.p[i];
        }

        size = str.size;

        return *this;
    }
    mystring & insert(int loc , const char * str){
        mystring temp(str);
        return insert(loc,temp);
    }
    mystring & insert(int loc , const mystring & str){

        if (loc < 0 || loc > size) return * this;

        if (size + str.size > size_mem){
        
            size_mem = 2 *(size + str.size);

            char * prev = p;
            p = new char[size_mem];

            int i ; 
            for (i =0; i < loc ; i ++){
                p[i] = prev[i];
            }

            for (int j = 0 ; j < str.size ; j ++){
                p[i+j] = str.p[j];
            }

            for (; i < size ; i ++){
                p[str.size + i] = prev[i];
            }

            delete [] prev ;

            size = size + str.size;
            
            return *this ; 
        }
        
        for (int i = size -1 ; i >= loc ; i --){
            p[i + str.size]= p[i];
        }
        for (int i =0; i < str.size ; i++){
            p[i+loc] = str.p[i];
        }
        

        size_mem = 2 *(size + str.size);
        size = size +str.size;
        
        
        
        return * this;
    }

    bool find(const char * str){
        mystring tmp(str);
        return find(str);
    }
    // 이거 세그먼테이션 오류가 일어남
    bool find(mystring & substr){
        int substr_len = substr.size;
        for (int i =0 ; i < size ; i++){
            if (substr.p[0] == p[i]){
                if (size-i < substr_len){
                    return false;
                }else{
                    for (int j = i+1 ; j < substr_len ; j++){
                        if (substr.p[j]!=p[j]){
                            return false;}
                    }
                    return true ;
                }
            }
        }
        return false;
    }

    mystring & erase(int loc , int num){

        if (num < 0 || loc < 0 || loc > size) return *this ;

        for (int i =loc + num ; i < size ; i ++){
            p[i - num] = p[i];
        }

        size -= num;
        return *this;
    }


    bool same(const char * str){
        if (size !=strlen(str))
            return false;
        for (int i =0; i < size ; i++){
            if (p[i]!=str[i])
                return false;
                
        }
        return true;
    }
    bool compare(const char * str){
        int iter = 0;
        if (strlen(str) > size) iter = size;
        else iter = strlen(str);
        
        for (int i = 0 ; i < iter ; i ++){
            if (p[i]!=str[i])
                return p[i] < str[i];
        
        if (strlen(str) >=size) 
            return false ;
        else 
            return true ;
        }
        return true;
    }
};


int main(){
    mystring ms("delicious");
    cout << ms.same("delicious") << endl;
    ms.print();
    ms.insert(0,"adsfasdfasdfasdfas");
    ms.print();
    ms.insert(10,"adsfasdfasdfasdfas");
    ms.print();
    //mystring mms(ms);
    cout << ms.find("ous") << endl;
    cout << ms.compare("zzz") << endl;
    ms.erase(0,3);
    ms.print();


    
    return 0;
}