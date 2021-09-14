#include <iostream>
#include <string.h>

class Marine{
    int hp ;
    int coord_x,coord_y ;
    int damage ;
    bool is_dead;
    char* name ;
    
    public :
    Marine();
    Marine(int x,int y,const char* marine_name);
    Marine(int x,int y);
    
    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    
    void show_status();
    ~Marine();
};

Marine::Marine(){
    hp = 50 ;
    coord_x = coord_y = 0 ;
    damage = 5;
    is_dead = false ;
    name = NULL ; 
}

Marine::Marine(int x , int y,const char* marine_name){
    name = new char[strlen(marine_name)+1];
    strcpy(name , marine_name);
    
    coord_x = x;
    coord_y = y;
    hp = 50 ;
    damage = 5;
    is_dead = false ;
}


void Marine::move(int x, int y ){
    coord_x = x;
    coord_y = y;
}


int Marine::attack(){return damage ; }

void Marine::be_attacked(int damage_earn){
    hp -=damage_earn ;
    if (hp <=0) is_dead = true;
}


void Marine::show_status(){
    std::cout << " *** Marine *** "<<name <<std::endl;
    std::cout << " Location : ( " << coord_x <<" , "<< coord_y<< " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl ;
}


Marine::~Marine(){
    std::cout << name << "의 소멸자 호출 ! " << std::endl;
    if (name !=NULL){
        delete[] name; // name 자체가 char의 배열로 동적할당 되었기 때문에 [] 필요
    }
}


int main(){
    Marine* marines[100];
    marines[0] = new Marine(2,3,"Marine_2");
    marines[1] = new Marine(3,5,"Marine_1");
    
    marines[0] -> show_status();
    marines[1] -> show_status();
    
    std::cout << std::endl << "마린1이 마린2를 공격" << std::endl;
    
    
    marines[0] ->be_attacked(marines[1] -> attack());
    
    
    marines[0] -> show_status();
    marines[1] -> show_status();
    
    delete marines[0] ; 
    delete marines[1] ; 
    
}