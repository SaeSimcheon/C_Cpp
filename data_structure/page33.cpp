// 이 코드 암기

#include<iostream>
#include<sstream> // 
#include<algorithm> // 

//dynamic_array라는 이름의 클래스 템플릿 작성 및 주요 멤버 변수 선언

template<typename T> // template 다시
class dynamic_array{
    T* data; // 포인터 관련해서 다시
    std::size_t n ; //std::size_t 란?

// 배열 크기를 인자로 받는 생성자와 복사 생성자 추가
    public :
    dynamic_array(int n)
    {
        this->n = n ; // class 다시 
        data = new T[n]; // 동적 할당 다시
    }
    dynamic_array(const dynamic_array<T>& other) // 
    {
        n = other.n;
        data = new T[n];
        
        for (int i = 0 ; i <n ; i ++)
            data[i] = other[i];
    }
    T& operator[](int index)
    {
        return data[index];
    }
    const T& operator[](int index) const
    {
        return data[index];
    }
    
    T& at(int index)
    {
        if (index < n)
            return data[index];
        throw "Index";
    }
    
    
    std::size_t size() const{
        return n;
    }
    ~dynamic_array(){
        delete[] data;
    }
    
    T* begin(){return data;}
    const T* begin() const { return data;}
    T* end() { return data+n;}
    const T* end() const {return data + n ;}
    
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(),arr1.end(),result.begin());
        std::copy(arr2.begin(),arr2.end(),result.begin() + arr1.size());
        
        return result;
    }
    
    std::string to_string(const std::string& sep = ",")
    {
        if(n == 0)
            return "";
        
        std::ostringstream os ;
        os <<data[0];
        
        for (int i =1 ; i <n ; i ++)
            os <<sep <<data[i];
        
        return os.str();
    }
    
    
};


struct student
{
    std::string name ;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
    return (os << "[" << s.name <<"," <<s.standard << "]");
}




int main(){
    
    int nStudents;
    std::cout << "1반 학생 수 입력" ;
    std::cin >> nStudents;
    
    
    dynamic_array<student> class1(nStudents);
    
    for (int i = 0 ; i < nStudents; i ++){
        std::string name ;
        int standard;
        
        std::cout <<i+1<<"번째 학생 이름과 나이";
        std::cin >> name >> standard ;
        class1[i] = student{name, standard};
    }
    
    
    try{
        class1.at(nStudents) = student{"John",8};
    }
    catch(...){
        std::cout <<"예외 발생!" <<std::endl;
    }
    
    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 "<<class2.to_string() <<std::endl;
    
    auto class3 = class1 + class2;
    
    std::cout << "1반과 2반을 합쳐서 3반 생성" << class3.to_string() <<std::endl;
    
    return 0;
}