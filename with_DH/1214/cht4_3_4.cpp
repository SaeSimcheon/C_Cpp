#include <string.h>
#include <iostream>

using namespace std;


class Photon_Cannon {
    int hp , shield;
    int coord_x , coord_y;
    int damage;
    char * name ;

    public :
    Photon_Cannon(int x, int y );
    Photon_Cannon(int x, int y ,const char * cannon_name);
    Photon_Cannon(const Photon_Cannon & pc);
    ~Photon_Cannon() ;

    void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y ,const char * cannon_name){
    name = new char[strlen(cannon_name) +1];
    strcpy(name,cannon_name);

    cout << "생성자 호출 ! " << endl;
    hp = shield = 100 ;
    coord_x = x ;
    coord_y = y ;
    damage = 20;
}



Photon_Cannon::Photon_Cannon(int x, int y ){
    cout << "생성자 호출 ! " << endl;
    hp = shield = 100 ;
    coord_x = x ;
    coord_y = y ;
    damage = 20;
}


Photon_Cannon::Photon_Cannon(const Photon_Cannon & pc){
    cout << "생성자 호출 ! " << endl;
    hp = pc.hp;
    shield = pc.shield ;
    coord_x = pc.coord_x ;
    coord_y = pc.coord_x ;
    damage = pc.damage;

    name = new char[strlen(pc.name) +1];
    strcpy(name,pc.name);
    
}

void Photon_Cannon::show_status(){
    cout << "Photon Cannon " << endl;
    cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;
}

Photon_Cannon::~Photon_Cannon(){
    if (name) delete[] name ;
}


int main(){
    Photon_Cannon pc1(3,3,"cannon");
    Photon_Cannon pc2 = pc1; // 이렇게 해도 복사 생성자가 호출 됨.
    
    pc1.show_status() ; 
    pc2.show_status() ;
}






/*
class Photon_Cannon {
    int hp , shield;
    int coord_x , coord_y;
    int damage;
    char * name ;

    public :
    Photon_Cannon(int x, int y );
    Photon_Cannon(int x, int y ,const char * cannon_name);
    ~Photon_Cannon() ;

    void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y ,const char * cannon_name){
    name = new char[strlen(cannon_name) +1];
    strcpy(name,cannon_name);

    cout << "생성자 호출 ! " << endl;
    hp = shield = 100 ;
    coord_x = x ;
    coord_y = y ;
    damage = 20;
}



Photon_Cannon::Photon_Cannon(int x, int y ){
    cout << "생성자 호출 ! " << endl;
    hp = shield = 100 ;
    coord_x = x ;
    coord_y = y ;
    damage = 20;
}

void Photon_Cannon::show_status(){
    cout << "Photon Cannon " << endl;
    cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;
}

Photon_Cannon::~Photon_Cannon(){
    if (name) delete[] name ;
}


int main(){
    Photon_Cannon pc1(3,3,"cannon");
    Photon_Cannon pc2 = pc1; // 이렇게 해도 복사 생성자가 호출 됨.
    
    pc1.show_status() ; 
    pc2.show_status() ;
}
*/
/*
위 코드는 에러가 발생함.
디폴트 복사 생성자는 모든 변수에 대하여 1대1로 값을 그냥 복사해주는 역할을 함.
그에 따라 name까지 같은 값을 갖게되는데 -> 동일한 주소 값을 갖게 된다는 말.
이것 자체는 문제가 되지 않지만, 문제는 소멸자에서 발생. pc1이 먼저 파괴 되고
pc2가 파괴 된다면 이미 해제된 메모리에 다시 접근하게 되기 때문에 오류를 발생시킴.


-> 해결책은 깊은 복사. 단순히 대입만 해주는 것을 얕은 복사라고 부름. 컴파일러가 생성하는
디폴트 복사 생성자의 경우 얕은 복사 밖에 할 수 없으므로 깊은 복사가 필요한 경우에는
사용자가 직접 복사 생성자를 만들어야함.
*/