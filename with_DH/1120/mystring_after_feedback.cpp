/*
1125 피드백

- mystring을 인자로 받아서 복사 생성자 -> 깊은 복사를 하기 위함
- 

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
    
    ~mystring(){// 소멸자는 인자를 받지 않는다
        delete[] p;
    }
    void print() const {
        cout << p << endl;
    }
    
    
    mystring & addstring(const char * _added){
        int added_len = strlen(_added) ;
        
        if (size_mem > size + added_len){    
            for (int i =0 ; i < added_len; i ++){
                p[size+i] = _added[i];
            }
            size = size+added_len;
        }else{
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
    ms.addstring("adsfasdfasdfasdfas");
    ms.print();
    ms.addstring("adsfasdfasdfasdfas");
    ms.print();
    cout << ms.find("ous") << endl;
    cout << ms.compare("zzz") << endl;
    


    
    return 0;
}