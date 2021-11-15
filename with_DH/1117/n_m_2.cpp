#include <iostream>
#include <vector>
#include<string>
#include<set>

// 순서 상관 없이 포함한 원소를 기준으로 중복여부 따짐
// 1에서 문자열을 사용한 것과 달리 2d vector를 사용해서 
// 모든 경우의 수에 대하여 수집한 후에 set을 통하여 중복 제거
using namespace std;
void dfs(vector<int> & check, vector<vector<int>> & ans,int M ,const int & N){
    if ( M == 0){
        vector<int> can ;
        for (int i =0; i < N ; i ++){
            if(check[i]==1)
                can.push_back(i+1);
        }
        ans.push_back(can);
        return ;
    }else{
        for (int i =0; i < N ; i ++){
            if (check[i]==0){
                check[i]=1;
                dfs(check,ans,M-1,N);
                check[i]=0;
            }
        }
        
    }
    
}


int main(){
    
    freopen("input.txt", "rt", stdin);
    int N , M ;
    cin >> N >> M ;
    vector<int> vec(N,0);
    vector<vector<int>> ans;
    
    dfs(vec,ans,M,N);
    
    set<vector<int>> ss(ans.begin(),ans.end());
    
    for (auto i : ss)
    {for (auto ii : i)
    cout <<ii<< ' ';
    cout <<'\n';}
    
    return 0;
}