#include <iostream>
#include <string>
using namespace std;

int main(){
  int primes[] = {2,3,4,5,6,7,78,8};

  for (int i : primes)
    {if (i == 2) continue;
    if (i == 4) break;
    std::cout << i <<" ";
    
    }
    
    //범위 기반 for문
    // 
}


