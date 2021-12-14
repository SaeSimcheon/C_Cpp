#include <iostream>
#include <string.h>

using namespace std;
class Marine {
    int hp;
    int coord_x , coord_y;
    int damage ;
    bool is_dead;
    char * name;

    public :
    Marine();
    Marine(int x, int y ,const char * marine_name);
    Marine(int x, int y );
    ~Marine();


    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y );

    void show_status();
};


Marine::Marine(){
    hp = 50 ;
    coord_x = coord_y = 0 ;
    damage = 5 ;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x , int y ,const char * marine_name){
    name = new char[strlen(marine_name) +1];
    strcpy(name,marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage =5 ;
    is_dead= false;
}

Marine::Marine(int x , int y ){
    
    
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage =5 ;
    is_dead= false;
}


void Marine::move(int x, int y){
    coord_x =x;
    coord_y = y;
}

int Marine::attack(){
    return damage;
}

void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <=0) is_dead= true;
}

void Marine::show_status(){
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    cout << " Location : ( " << coord_x << ", "<< coord_y << " ) "
    << endl;
    cout << " HP : " << hp << endl;
}
Marine :: ~Marine(){
    cout << name << " out" << endl;
    delete[] name ;
}
// 소멸자는 어떤 인자를 갖지 않음. -> 소멸자는 오버로딩도 되지 않음.
// name 자체가 char의 배열로 동적할당 되었기 때문에 delete 역시
// delete [] name으로 반드시 []을 써주어야함.


// 소멸자는 동적으로 할당 받은 메모리를 해제하는 일을 하기도 하지만
// 쓰레드 사이에서 lock 된 것을 푸는 역할 같은 것을 할 수 있음.

int main(){
    /*
    Marine marine1(2,3);
    Marine marine2(3,5);

    marine1.show_status();
    marine2.show_status();

    cout << endl << "마린 1이 마린 2를 공격 !" << endl;

    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    */
    Marine * marines[100]; 
    
    // Marine marines[100];도 불가능하지는 않음.
    // 하지만 동적할당을 위해서는 pointer가 필요하다

    // Marine이라는 객체의 포인터를 담을 배열 생성.
    marines[0] = new Marine(2,3,"m1"); // c++은 메모리 동적할당 할때 생성자를 
    // 자동으로 호출하는 것이 가능하다 그런데 자동 ??
    marines[1] = new Marine(3,5,"m2"); 

    marines[0]-> show_status();
    marines[1]-> show_status();

    cout << endl << "마린 1이 마린 2를 공격 !" << endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];   
    delete marines[1];   

}

// 디폴트 소멸자 또한 존재함. 디폴트 소멸자 내부에서는 아무런 작업도 수행하지 않는다.

