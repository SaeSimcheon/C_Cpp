#include <iostream>
#include <vector>
#include <numeric>
#include <list>
using namespace std;

void dfs(vector<vector<int>> & mat,const int & node,const int & start){
    if (node == start){// 최초의 노드 출력
        cout << start +1<< " ";
    }
    if (accumulate(mat[node].begin(),mat[node].end(),0)==0){
        return ; // 종료 조건은 도착한 node의 앞으로 방문할 수 있는 노드의 수 합이 1이 됨.
    }else{
        for (int i=0 ; i < mat[node].size(); i++){

            if (mat[node][i] == 1){
                for (int j = i ; j <mat[node].size();j++){
                    mat[node][j] =0;
                    mat[j][node] =0;
                }// 방문한 노드에 관한 간선은 모두 없앰
                cout <<i +1 << " ";// 다음 dfs를 호출하기 전에 출력
                dfs(mat,i,start);

            }
        }
        
       
    }
}


int main(){
    int N,M,V;
    cin >> N >> M >> V ;
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
    dfs(vec,V-1,V-1);
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