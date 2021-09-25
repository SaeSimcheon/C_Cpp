#include<iostream>
#include<array>


void print(std::array<int,5> arr) ;

int main(){

    // Hello 출력
    std::cout << "Hello" <<std::endl;
    // 각 요소가 int이고 크기가 10인 배열 선언. 배열 이름은 arr1
    std::array<int,10> arr1;
    // 첫번째 원소에 1 넣기
    arr1[0] = 1;
    // arr1의 첫번째 원소 출력
    std::cout << arr1[0] << std::endl; 
    
    // int 배열 만들고 원소 5개 넣기 '이름 arr2'
    std::array<int,5> arr2 ={1,2,3,4,5};
    // 원소 개수 확인하기
    for(int i = 0 ;i < arr2.size();i++)
    std::cout <<arr2[i] << " ";
    std::cout <<std::endl;

    print(arr2);
    
}

// 함수 이름 print, int타입의 5개 원소 갖는 배열을 입력으로 받아서 출력하는 함수
void print(std::array<int,5> arr)
{
    for (auto ele : arr)
    std::cout <<ele <<", ";
}