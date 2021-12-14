#include <string.h>
#include <iostream>

using namespace std;

class Photon_Cannon {
    int hp , shield;
    int coord_x , coord_y;
    int damage;

    public :
    Photon_Cannon(int x, int y );
    //Photon_Cannon(const Photon_Cannon& pc);

    void show_status();
};
/*
// 복사 생성자의 표준적인 정의
Photon_Cannon::Photon_Cannon(const Photon_Cannon & pc){
    cout << "복사 생성자 호출 ! " << endl;

    hp = pc.hp;
    shield= pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;

    damage = pc.damage;
}

제거 해도 위 코드와 동일한 기능을 하는 디폴트 복사생성자가 있음.
디폴트 복사생성자의 경우 기존의 디폴트 생성자와 소멸자가 아무 일도 
하지 않는 것과 달리 실제로 '복사'의 기능을 한다.

*/
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

int main(){
    Photon_Cannon pc1(3,3);
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2; // 이렇게 해도 복사 생성자가 호출 됨.
    pc1 = pc2; // 이건 복사생성이 아님 !
    pc1.show_status() ; 
    pc2.show_status() ;
}