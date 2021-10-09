#include <iostream>
using namespace std;

class Circle{
    int radius;
    public :
        Circle(){radius = 1 ;}
        Circle(int radius){ this -> radius =radius;}
        void setRadius(int radius){this -> radius = radius;}
        double getArea(){return 3.14* radius*radius;}
};

Circle getCircle(){
    Circle tmp(30);
    return tmp;
}

int main(){
    Circle c,c1(5),c2(30);
    cout << c.getArea() << endl;
    cout << "c1 "<< c1.getArea() << endl;
    cout << "c2 "<< c2.getArea() << endl;
    c1 = c2;
    cout << "c1 "<< c1.getArea() << endl;

    cout << c.getArea() << endl;

    c = getCircle();
    cout << c.getArea() <<endl;
}

