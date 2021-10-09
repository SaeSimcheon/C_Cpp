#include <iostream>
using namespace std;

class Circle{
    private :
        int radius;
    public :
        Circle();
        Circle(int r);
        ~Circle();
        double getArea(){ return 3.14 * radius * radius;}
        int getRadius(){return radius;}
        void setRadius(int radius){this -> radius = radius ;}
};

Circle::Circle(){
    radius =1 ;
    cout << "생성자 radius = " << radius << endl ; 
}

Circle::Circle(int radius){
    this -> radius = radius;
    cout << "생성자 radius = " << radius << endl ; 
}


Circle::~Circle(){
    cout << "소멸자 radius = " << radius << endl ; 
}


void increase(Circle c){
    
    int r = c.getRadius();
    c.setRadius(r + 1);
    
}


void increase_p(Circle *c){
    
    int r = c->getRadius();
    c->setRadius(r + 1);
    
}


int main(){
    Circle waffle(30);
    increase(waffle);
    cout <<"Result of Value "<<waffle.getRadius() << endl;
    increase_p(&waffle);
    cout << "Result of Address "<<waffle.getRadius() << endl;
}