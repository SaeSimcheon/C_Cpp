#include <string.h>

#include <iostream>


class Photon_cannon{
    int hp , shield;
    int coord_x,coord_y;
    int damage;
    
    public :
    Photon_cannon(int x, int y);
    //Photon_cannon(const Photon_cannon& pc);
    
    void show_status();
};

/*
Photon_cannon::Photon_cannon(const Photon_cannon&pc){
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
*/
Photon_cannon::Photon_cannon(int x, int y){
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x =x ;
    coord_y = y;
    damage = 20;
}

void Photon_cannon::show_status(){
    std::cout << "Photon_cannon" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl ;
    std::cout << " HP : " << hp << std::endl;
}


int main(){
    Photon_cannon pc1(3,3);
    Photon_cannon pc2(pc1);
    Photon_cannon pc3 =pc2 ;
    
    pc1.show_status();
    pc2.show_status();
}


