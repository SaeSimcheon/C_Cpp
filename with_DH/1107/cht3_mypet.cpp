//문제점 : 비슷한 특성을 가진 구조체를 만든다면, 해당 구조체마다 받는 인자만 다른 함수를 많이 만들어야함
// 귀찮게 구초제를 인자로 계속 넣어줘야함
// 실수로 메모리만 할당받고 초기화하지 않았는데 해당 메모리를 사용하는 문제
// 대상이 실제로 존재하지 않지만, 문법적으로 오류가 없어서 실행되는 프로그램

#include <iostream>

typedef struct animal{
    char name[30];
    int age ;
    
    int health ;
    int food ;
    int clean;
    
} animal;


void create(animal * ann){
    std::cout << " 이름 ";
    std::cin >> ann->name;
    
    std::cout << " 나이 ";
    std::cin >> ann->age;
    
    ann->health = 100;
    ann->food = 100;
    ann->clean = 100;
    
}

void play(animal * ann){
    ann->health +=10;
    ann->food -=20;
    ann->clean -=30;
}

void one_day(animal *ann){
    ann->health -=10;
    ann->food -=30;
    ann->clean -=20;
}

void show_stat(animal *ann){
    std::cout << ann->name << "의 상태" <<std::endl;
    std::cout << ann->health << " 체력" <<std::endl;
    std::cout << ann->food << " 배부름" <<std::endl;
    std::cout << ann->clean << " 청결" <<std::endl;
}

int main(){
    animal *list[10];
    int animal_num = 0;
    
    for (;;){
        std::cout << "1.동 추 " << std::endl;
        std::cout << "2.놀 기 " << std::endl;
        std::cout << "3.상태보기 " << std::endl;
        
        int input ;
        std::cin >>input ;
        
        switch (input){
            int play_with;
            case 1:
                list[animal_num] = new animal;
                create(list[animal_num]);
                
                animal_num++;
                break;
            case 2 :
                std::cout << "누 놀 :";
                std::cin >>play_with;
                
                if (play_with < animal_num) play(list[play_with]);
                break;
            case 3 :
                std::cout << "누 보 :";
                std::cin >> play_with ;
                if (play_with < animal_num) show_stat(list[play_with]);
                break;
        }
        
        for (int i =0 ; i !=animal_num ; i++)
            one_day(list[i]);
    }
    for (int i =0 ; i !=animal_num; i ++){
        delete list[i];
    }
    
    return 0;
}