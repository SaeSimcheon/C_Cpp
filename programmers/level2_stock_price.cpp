#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 헤드에서 뽑고 안에 있는 원소들 판단하면 됨


vector<int> solution(vector<int> prices) {
    
    vector<int> answer(prices.size(),0);
    

    /*
    T : price at this time
    */
    
    for (int i = 0 ; i < prices.size(); i ++){
        int T = prices[i];
        for (int j = i+1 ; j < prices.size(); j ++){
            if (T <=prices[j]){
                answer[i]+=1;
            }else{
                answer[i]+=1;
                break;
            }
        }
    }

    
    return answer;
}