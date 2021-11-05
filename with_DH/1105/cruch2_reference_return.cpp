#include <iostream>
// warning: reference to local variable 'a' returned
/*
int& function(){
    int a =2;
    return a;
}

int main(){
    int b = function();
    std::cout <<b <<std::endl;
    return 0;
}
*/



int function(){
    int a = 5;
    std::cout <<&a <<std::endl;
    return a;
}

int main(){
    //std::cout << &&function() <<std::endl;
    const int  & c = function();
    int && cc = function();

    //std::cout <<&5 <<std::endl;
    //printf("%p",5);

    
    std::cout <<c <<std::endl;
    std::cout <<&c <<std::endl;
    std::cout <<&cc <<std::endl;
    return 0;
}



/*
int& function(int &a){
    a =2;
    return a;
}

int main(){
    int c = 5;
    std::cout <<c <<std::endl;
    int b = function(c);
    std::cout <<c <<std::endl;
    std::cout <<b <<std::endl;
    return 0;
}
*/