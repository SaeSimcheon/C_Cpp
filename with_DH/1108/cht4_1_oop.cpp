#include <iostream>

class animal{
    private:
    int food ;
    int weight ;

    public :

    void set_animal(int _food,int _weight){
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc){
        food +=inc ;
        weight +=(inc/3);
    }
    void view_stat(){
        std::cout << "이 동물의 food : " << food << std::endl;
        std::cout << "이 동물의 weight : " << weight << std::endl;
    }
}; // 세미콜론

int main(){
    animal ann;
    ann.view_stat(); // 각 멤버 변수 초기화 전
    ann.set_animal(100,50);
    ann.increase_food(30);

    ann.view_stat();
    return 0;
}