#include <iostream>

class Circle{
    private:
        int radius;
    public:
        Circle();
        Circle(int r);
        ~Circle();
        double getArea(){return 3.14*radius*radius;}
        int getRadius(){return radius ;}
        void setRadius(int radius ){this -> radius = radius ;}
};


Circle::Circle(){
    radius =1;
    std::cout << "생성자 실행" << radius << std::endl;
}

Circle::Circle(int radius){
    this -> radius =radius ;
    std::cout << "생성자 실행" << radius << std::endl;
}


Circle::~Circle(){
    std::cout <<"소멸자 실행" << radius << std::endl;
}

void increase(Circle c){
    int r = c.getRadius();
    c.setRadius(r+1);
}



int main(){
    Circle www;
    std::cout << www.getRadius() << std::endl;
    Circle waffle(30) ; 
    increase(waffle);
    std::cout << waffle.getRadius() << std::endl;
}
