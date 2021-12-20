#include<string>
#include <iostream>
class employee{
    std::string name;
    int age;
    std::string position;
    int rank;
    
    public:
    employee(std::string name , int age , std::string position, int rank): name(name), age(age),position(position),rank(rank){}
    
    employee(const employee& employee){
        name = employee.name ;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }
    employee(){}
    
    void print_info(){
        std::cout << name << " ( " << position << " , "<< age << ") ==> " << calculate_pay() << "만원" << std::endl;
    }
    
    int calculate_pay(){ return 200 + rank * 50;}
};


class Manager {
    std::string name;
    int age;
    std::string position;
    
    int rank;
    int year_of_service;
    
    public:
    Manager(std::string name , int age , std::string position, int rank,int year_of_service)
        : year_of_service(year_of_service),
    name(name),
    age(age),
    position(position),
    rank(rank){}
    
    Manager(const Manager& manager){
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }
    
    Manager(){}
    
    int calculate_pay(){ return 200 + rank * 50 + 5 * year_of_service;}
    void print_info(){
        std::cout << name << " (" << position << " , " << age << ", "
            << year_of_service << "년차) ==> " << calculate_pay() << "만원"
            << std::endl;
    }
};




class EmployeeList{
    int alloc_employee;
    int current_employee;
    int current_manager;
    //employee ** employee_list;
    employee * employee_list;
    
    //Manager ** manager_list;
    Manager * manager_list;
    
    public :
    EmployeeList(int alloc_employee):alloc_employee(alloc_employee){
        //employee_list = new employee*[alloc_employee];
        employee_list = new employee[alloc_employee];
        
        //manager_list = new Manager*[alloc_employee];
        manager_list = new Manager[alloc_employee];
        
        // 왜 [size_level_1][1]로 짜는 거지?
        // 이렇게 안 짜고 Employee * employee_list; 이건 별론가?
        current_employee = 0 ;
        current_manager = 0 ;
    }
    //void add_employee(employee * employee){
    void add_employee(employee _employee){
        employee_list[current_employee] = _employee;
        current_employee++;
    }
    //void add_manager(Manager * manager){
    void add_manager(Manager _manager){
        manager_list[current_manager] = _manager;
        current_manager++;
    }
    
    int currnet_employee_num(){ return current_employee+current_manager;}
    
    void print_employee_info(){
        int total_pay = 0;
        for (int i = 0 ; i < current_employee; i ++){
            employee_list[i].print_info();
            total_pay += employee_list[i].calculate_pay();
        }
        
        for (int i = 0 ; i < current_manager; i ++){
            manager_list[i].print_info();
            total_pay += manager_list[i].calculate_pay();
        }
        
        std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
    }
    
    
    ~EmployeeList(){
        /*
        for (int i =0 ; i < current_employee ; i ++){
            delete employee_list[i]; // 하위 
        }
        */
        /*
        for (int i =0 ; i < current_manager ; i ++){
            delete manager_list[i]; // 하위 
        }
        */
        delete[] manager_list;
        delete[] employee_list; // 상위
    }
    
};

int main(){
    EmployeeList emp_list(10);
    /*
    emp_list.add_employee(new employee("노홍철",34,"평사원",1));
    emp_list.add_employee(new employee("하하",34,"평사원",1));
    emp_list.add_employee(new employee("정형돈",34,"대리",2));
    */
    emp_list.add_manager(Manager("유재석",41,"부장",7,12));
    emp_list.add_employee( employee("노홍철",34,"평사원",1));
    emp_list.add_employee( employee("하하",34,"평사원",1));
    emp_list.add_employee( employee("정형돈",34,"대리",2));
    // 내 생각대로 그냥 string 만들때처럼 포인터 하나 사용해서 하는 것 가능함.
    emp_list.print_employee_info();
}
