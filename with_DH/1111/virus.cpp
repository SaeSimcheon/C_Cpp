#include <iostream>
#include <vector>
#include <numeric>

using namespace std;




void dfs(const vector<vector<int>> & mat, vector<int> & check,const int & node,int & ans){
    ans +=1;
    check[node] =1 ;
    
    for (int j =0; j < check.size();j++ ){
        if(mat[node][j]&&check[j]==0)
            dfs(mat,check,j,ans);
    }
    
    
}



int main(){
    
    int N,M;
    
    freopen("input.txt", "rt", stdin);
    cin >> N ;
    cin >> M ;
    vector<vector<int>> vec(N,vector<int>(N,0));
    
    vector<int> ch(N,0);
    
    for (int i =0 ; i < M ; i++){
        int o1,o2;
        cin >> o1 >> o2 ;
        vec[o1-1][o2-1] =1;
        vec[o2-1][o1-1] =1;
    }
    
    int answer =0;
    
    
    dfs(vec,ch,0,answer);
    cout << answer-1<<endl;;
}
