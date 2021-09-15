#include <iostream>

#include <string>

int main(){
    
    std::string s = "abc";
    std::string s2 = std::string("abc");
    std::string s1("abc");
    
    std::cout << s << std::endl;
    
    std::cout << s+s2 << std::endl;
    
    std::cout << s.length() << std::endl;
    
    //std::cout << s == s1 << std::endl;
    
    std::cout << s2 << std::endl;
    std::cout << s1 << std::endl;
    
    return 0;
}