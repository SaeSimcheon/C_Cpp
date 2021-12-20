// friend 키워드

class A{
    private :
    void private_fun(){};
    int private_num;
    
    friend class B ;
    
    friend void func();
};

class B{
    public :
    void b(){
        A a;
        
        a.private_fun();
        a.private_num = 2;
    }
};



void func(){
    A a;
    
    a.private_fun();
    a.private_num = 2;
}


int main(){}