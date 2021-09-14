#include <iostream>


class A {
    int x ;
    public :
    A(int c ): x(c) {}
    
    int & access_x() {std::cout << "address of x "<< &x << std::endl; return x ;}
    int get_x() {return x ;}
    void show_x() { std :: cout << x <<std :: endl;}  
};

int main(){
    A a(5); // 인스턴스 생성
    
    a.show_x(); // 상태 확인
    
    int& c = a.access_x(); // access
    
    printf("%d\n",c);
    printf("address of c %p\n",&c);
    
    int k =10 ;
    
    int & j = k ;
    
    int u = j ;
    int & e = j;
    
    std::cout << "k : " << k  <<"j : " << j <<"e : " << e << "u : " << u  << std::endl;
    
    k =11 ;
    
    std::cout << "k : " << k  <<"j : " << j <<"e : " << e << "u : " << u  << std::endl;
    
    
    c=4;
    
    a.show_x();
    
    int d = a.access_x();
    
    
    
    printf("%d\n",d);
    printf("%p\n",&d);
    d=3;
    a.show_x();
    
}

