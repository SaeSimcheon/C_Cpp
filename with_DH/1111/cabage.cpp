#include<iostream>
#include<vector>

using namespace std;
void dfs(vector<vector<int>>&  mat,const vector<int> & position){
    vector<vector<int>> D{{0,1},{0,-1},{-1,0},{1,0}};
    vector<int> next(2,0);
    
    mat[position[0]][position[1]] =0;
    
    
    for(auto j : D){
            if (position[0] + j[0]== mat.size()||position[1] + j[1]== mat[0].size()||position[0] + j[0] <0 ||position[1] + j[1] <0)
                continue;
            if(mat[position[0] + j[0]][position[1] + j[1]]==1){
                next[0]= position[0] + j[0];
                next[1]= position[1] + j[1];
                
        
                dfs(mat,next);
            }
    }
}

int solve(vector<vector<int>> mat,const int & N,const int & M,const vector<vector<int>>& p_start ){
    int ans =0;
    for (auto jj : p_start){
        if (mat[jj[0]][jj[1]]){
            dfs(mat,jj);
            ans+=1;
        }
    }
    return ans;
}


int main(){
    freopen("input.txt", "rt", stdin);
    int prob_num, N , M , K;
    cin >> prob_num ;
    for (int i = 0 ; i< prob_num;i++){
        cin >> N ;
        cin >> M ;
        cin >> K ;
        vector<vector<int>> vec(N,vector<int>(M,0));
        vector<vector<int>> p_can(K,vector<int>(2,0));
        for (int i =0 ; i < K ; i++){
            int o1,o2;
            cin >> o1 ;
            cin >>o2;
         
            vec[o1][o2] =1;
            
            p_can[i][0]=o1;
            p_can[i][1]=o2;
        }
        /*
        for ( auto i :vec){
            for( auto j :i)
                cout << j; 
            cout << endl;
        }
        vector<vector<int>> D{{0,1},{0,-1},{-1,0},{1,0}};
        for (auto j : D) cout << j[0] <<j[1] <<endl;
        */
    cout << solve(vec,N,M,p_can) << endl;
    }
}
    
    
    
    
    
    

