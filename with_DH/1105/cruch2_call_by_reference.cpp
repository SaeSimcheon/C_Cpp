#include <iostream>

int change(int &p){
    p = 3;
    return 0;
}


int main(){
    int number =5;

    
    std::cout << number << std::endl;
    change(number);
    std::cout << number << std::endl;

}