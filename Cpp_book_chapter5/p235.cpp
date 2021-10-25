#include <iostream>
using namespace std;
class Circle {
    int radius ;
    public:
    Circle() { cout <<this -> radius << endl;// 0으로 초기화 되어 있음
            radius = 1; // 이 라인 이후에 
             cout <<this -> radius << endl; // 인스턴스의 멤버함수 직접 호출.
             cout << radius << endl; // 멤버 변수의 값이 1이 된 것을 확인할 수 있음. 위와 결과 같음.
             // 매개변수와 무관하게 겹치지 않게 호출되는 경우에는 인스턴스의 멤버 변수가 호출됨.
             }
    Circle(int radius){this -> radius = radius;}
    void setRadius(int radius){this ->radius = radius ;}
    double getArea() {return 3.14 * radius *radius;}
};


int main(){
    Circle circle;
    cout << circle.getArea() << endl;
    Circle &refc = circle;// 클래스의 인스턴스에 대한 참조
    refc.setRadius(10); // 마치 해당 인스턴스처럼 사용할 수 있음.
    cout << refc.getArea() << " " << circle.getArea() <<endl;// 마치 해당 인스턴스처럼 사용할 수 있음. 참조 변수를 통하여 변경했는데
    // 본 인스턴스 역시 함께 변화된 것을 확인할 수 있음.
}
