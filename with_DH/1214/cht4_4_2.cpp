// C에서의 static 변수
// 
/*

#include <stdio.h>

int* function() {
  static int a = 2;
  return &a;
}

int main() {
  int* pa = function();
  printf("%d \n", *pa);
}

지역을 빠져나가도 파괴되지 않는 변수
정적 변수

특정 함수 안에서 static을 앞에 붙여줌으로써 사용할 수 있음

*/

#include <iostream>
// static 변수는 클래스의 모든 객체들이 공유하는 변수.
class Marine{
    static int total_marine_num ;
    //이건 가능 const static int total_marine_num =0;
    
    int hp;
    int coord_x , coord_y;
    bool is_dead;

    const int default_damage;

    public:

    Marine();
    Marine(int x ,int y );
    Marine(int x, int y  , int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine();
    ~Marine() { total_marine_num--;}
};

int Marine::total_marine_num = 0 ;
// static 변수는 class 내부에서 초기화 시킬 수 없음.
// 단, 예외적으로 const static인 경우는 가능함.
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0),default_damage(5),is_dead(false){
        total_marine_num++;
    }

Marine::Marine(int x, int y)
    : hp(50), coord_x(x), coord_y(y),default_damage(5),is_dead(false){
        total_marine_num++;
    }

Marine::Marine(int x, int y,int default_damage)
    : hp(50), coord_x(x), coord_y(y),default_damage(default_damage),is_dead(false){
        total_marine_num++;
    }

int Marine::attack(){ return default_damage ; }

void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status(){
    std::cout << " ** Marine ** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
    << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 " << total_marine_num << std::endl;
}

void Marine::show_total_marine(){
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

void create_marine(){
    Marine marine3(10,10,4);
    marine3.show_status();
}

int main(){
    Marine::show_total_marine(); // 인스턴시 생성과 무관하게 클래스 자체에서 호출할 수 있음.
    // 어떤 객체에도 종속되지 않기 대문에 객체.멤버함수 형태로 쓰지 못한다.
    Marine marine1(2,3,5);
    marine1.show_status();
    Marine::show_total_marine();
    Marine marine2(3,5,10);
    marine2.show_status();
    Marine::show_total_marine();

    create_marine();

    std::cout << std::endl << "마린 1이 마린 2를 공격 !" << std::endl;

    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}

