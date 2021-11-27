#include <string>
#include <vector>
#include <iostream>
// 왼쪽 대각선 위에서 오른쪽 대각선 아래로 1씩 커짐
// 예를 들면 12345
// 다음줄 22345 이렇게 됨 1 기준에서 아래로 추가로 1번째 줄
// 33345 이렇게 됨 1 기준에서 아래로 추가로 2번째 줄
// 44445 이렇게 됨 1 기준에서 아래로 추가로 3번째 줄 -> 3번째까지 3더함 4로 쭉 나열 -> 주기만큼 더함 주기까지 1에서 주기만큼 더함
// 55555 이렇게 됨 1 기준에서 아래로 추가로 4번째 줄
// 주기는 left 기준에서 n 몫에 해당하는 부분이 아래로 추가되는 줄

// left right 

using namespace std;


vector <int> Avector(int n , int iter){
    vector<int> out ;
    for (int i =0; i < iter ; i ++){
        out.push_back(iter);
    }
    for (int i = iter+1 ; i < n+1 ; i ++){
        out.push_back(i);
    }
    return out ; 
}


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (int i = left/n ; i < right/n +1 ; i++){
        vector<int> avec = Avector(n,i+1);
        int st = 0;
        int ed = avec.size();
        if (i == left/n) st += left%n;
        if (i == right/n) ed = right%n+1;
        
        for (int j =st;j < ed; j ++){
            answer.push_back(avec[j]);
        }
    }
        
    
    
    
    return answer;
}