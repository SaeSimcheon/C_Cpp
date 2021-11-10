
//https://www.acmicpc.net/source/11405777
//https://github.com/kjyoa09/Cpp/blob/main/BOJ/Silver/1260%20DFS%EC%99%80%20BFS.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <list>

using namespace std;

void dfs(const vector<vector<int>> & mat,const int & node,const int & start,vector<int> &ch ){
    if (node == start){// 최초의 노드 출력
    cout << node+1<<' ';
        ch[node]=1;
    }
    
    int cnt =0;
    for (int i=0 ; i < mat[node].size();i++){
        if (mat[node][i]==1){
            if (ch[i]==1)
                cnt +=1;
        }
        }
    int comp =accumulate(mat[node].begin(),mat[node].end(),0);

    if (comp== cnt)
        return;

    for (int i=0;i<mat[node].size();i++){
        if (mat[node][i]==1){
            if(ch[i]==0){
            ch[i]=1;
            cout << i+1<<' ';
            dfs(mat,i,start,ch);
            }
        }
        

    }
    
}


int main(){
    //freopen("input.txt", "rt", stdin);
    int N,M,V;
    cin >> N >> M >> V ;
    vector<int> dfs_ch(N,0);
    vector<vector<int>> vec(N,vector<int>(N,0));
    vector<vector<int>> vec1(N,vector<int>(N,0));
    for (int i =0 ; i < M ; i++){
        int o1,o2;
        cin >> o1 >> o2 ;
        vec[o1-1][o2-1] =1;
        vec[o2-1][o1-1] =1;
        vec1[o1-1][o2-1] =1;
        vec1[o2-1][o1-1] =1;
    }
    dfs(vec,V-1,V-1,dfs_ch);
    cout <<endl;
    
    list<int> heap ;

    int testi=0;
    heap.push_front(V-1);
    vector<int> ch(N,0);

    while(heap.size()!=0){
        
        int head = heap.front();
        
        if (head == V-1){
            cout << head+1<< ' ';
        }
        
        heap.pop_front();
        for (int i=0 ; i < vec1[head].size(); i++){
            if(vec1[head][i]==1&&ch[i]==0){
                vec1[head][i] = 0;
                vec1[i][head] =0;
                    ch[i] =1;
                    cout << i +1<< ' ';
                    heap.push_back(i);
                    }
                
            }
        }
    
    
    return 0;
}