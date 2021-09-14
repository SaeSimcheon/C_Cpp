#include <iostream>

class My{
    
    public:
    My(int capacity);
    //explicit MyString(int capacity);
    My (char * str);
    My (const My& str);
    
};

void Do(My s ){
    std::cout << "Do" << std::endl;
}




My::My(const char * str){
    std::cout << str << std::endl;
}


My::My(const My& str){
    std::cout << str << std::endl;
}

int main(){
    Do(3);
}

