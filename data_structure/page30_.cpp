#include <iostream>
#include <array>

// 가변길이 배열을 인풋으로 받는 함수의 프로토타입 작성
template<std::size_t N>
void print(std::array<int, N> arr);



int main(){
    // int 타입 사이즈 5 배열 작성 이름 arr
    std::array<int , 5 > arr = {1,2,3,4,5};
    // print 함수 사용
    print(arr);
    return 0;
}


// 가변 길이 배열을 인풋으로 받는 함수 작성
template<std::size_t N>
void print(std::array<int, N> arr){
    // 배열의 시작과 끝을 반복자를 통하여 원소를 반환할 수 있도록 반복문 작성.
    for (auto it = arr.begin(); it !=arr.end();it ++){
        auto element =(*it);
        std::cout << element <<' ';
    }

}