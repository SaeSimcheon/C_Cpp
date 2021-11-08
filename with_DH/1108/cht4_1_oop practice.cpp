#include <iostream>

class Date{

    int year_;
    int month_;
    int day_;

    public :
    void setdate(int year,int month ,int date);
    void addday(int inc);
    void addmonth(int inc);
    void addyear(int inc);

    void showdate();

}; // 세미콜론

void Date::setdate(int year,int month,int date){
    this->year_ = year;
    this->month_ = month;
    this->day_ = date;
}

void Date::addday(int inc){
    if (this ->year_%100==0&&this ->year_%100==0){
        
    }
}

int main(){

}