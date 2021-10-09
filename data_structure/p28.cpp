#include <iostream>
#include <array>


template<size_t N>
void print_T(const std::array<int, N>& arr){
    for (auto ele : arr){
        std::cout <<ele << ",";
    }
    std::cout << std::endl;
}




void print(std::array<int, 5> arr){
    for (auto ele : arr){
        std::cout <<ele << ",";
    }
    std::cout << std::endl;
}


int main(){
    std::array<int , 10 > arr1 ;
    arr1[0] =1 ;
    std::cout << arr1[0] << std::endl;
    std::cout << arr1[1] << std::endl;
    std::cout <<"arr1 배열의 첫 번째 원소: " << arr1[0] << std :: endl;


    std::array<int , 4> arr2 ={1,2,3,4};

    for (int i = 0 ; i < arr2.size(); i++){
        std::cout << arr2[i] <<" ";
    }
    std::cout << std::endl;

    std::array<int,5> arr = {1,2,3,4,5};
    std::array<int,10> arr10; 
    std::array<int,20> arr20; 
    print(arr);
    print_T(arr);
    print_T(arr10);
    print_T(arr20);
    print_T(arr20);
    print_T(arr1);
    print_T(arr2);

    for(auto it = arr.begin();it != arr.end();it ++){
        auto element = (*it);
        std::cout <<element << ' ';
    }


}
