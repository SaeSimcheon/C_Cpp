#include <iostream>

using namespace std;
class Marine {
    int hp;
    int coord_x , coord_y;
    int damage ;
    bool is_dead;


    public :
    Marine();
    Marine(int x, int y );

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
    cout << " *** Marine *** " << endl;
    cout << " Location : ( " << coord_x << ", "<< coord_y << " ) "
    << endl;
    cout << " HP : " << hp << endl;
}


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
    marines[0] = new Marine(2,3); // c++은 메모리 동적할당 할때 생성자를 
    // 자동으로 호출하는 것이 가능하다 그런데 자동 ??
    marines[1] = new Marine(3,5); 

    marines[0]-> show_status();
    marines[1]-> show_status();

    cout << endl << "마린 1이 마린 2를 공격 !" << endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];   
    delete marines[1];   

}