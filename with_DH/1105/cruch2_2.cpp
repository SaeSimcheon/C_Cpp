#include <iostream>

int main(){
    int number =5;
    int & alias = number;

    alias =3;
    std::cout << number << std::endl;
    std::cout << alias << std::endl;

}