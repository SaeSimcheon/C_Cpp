#include<iostream>


int main(){
    int ** ddp;
    
    int ** dp;
    
    dp = new int *[10];
    
    for (int i = 0 ; i < 10; i ++) dp[i] = new int[20];
    
    std::cout << dp[0][19]<<std::endl;
    std::cout << NULL <<std::endl;
    return 0;
}