#include <iostream>
#include <array>


template <std::size_t N>
void print(std::array<int, N> arr);

int main()
{
    std::array<int , 5 > arr1 = {1,2,3,4,5};// 크기 5 int 타입 배열 초기화 원소는 12345
    print(arr1); // print 함수 사용
    return 0 ; // 함수 종료
}

// print함수 작성 :  
// 탬플릿을 통하여 길이가 정해지지 않은 int 타입 배열을 출력하는 함수 작성

template <std::size_t N> 
void print(std::array<int, N> arr)
{
    for (auto ele : arr)
    std::cout <<ele << ", ";
}