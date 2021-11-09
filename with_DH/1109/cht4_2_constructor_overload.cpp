#include <iostream>
#include <string>
using namespace std;


class Date{
    int year_;
    int month_;
    int day_;
    public :
    Date(){
        cout << "디폴트 생성자 호출" << endl;
    };
    Date(const int & yyyy,const int & mm,const int & dd){
        cout << "이건 개인 생성자 " << endl;
        year_ = yyyy;
        month_ = mm;
        day_ = dd;
    }

    void addyear(int inc){
        year_+=inc;
    }
    void addmonth(int inc){
        month_+=inc-1;
        year_ += month_/12;
        month_ += inc%12;
        month_=(month_ == 12 ? 12 : month_ %12);
    }

    int GetCurrentMonthTotalDays(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_day[month - 1];
    } else if (year % 4 == 0 && year % 100 != 0) {
        return 29;  // 윤년
    } else {
        return 28;
    }
    }
    void AddDay(int inc) {
    while (true) {
    // 현재 달의 총 일 수
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // 같은 달 안에 들어온다면;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // 다음달로 넘어가야 한다.
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      addmonth(1);
    }
  }
}
void ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}



};

int main() {
    Date deff = Date();
    Date deff1; 
    Date deff2() ;
    Date dd(2011,3,1);
    //dd.AddDay(2030);
    
    deff.ShowDate();
    deff1.ShowDate();
    dd.ShowDate();
    return 0;
}