#include <iostream>
#include <vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std ;


void tree(map<int,vector<int>> & _adj,map<int,vector<int>>& mapp,const int current,const int parent,const int & _N){
    for(auto i : _adj[current]){
        if(i !=parent){
            mapp[current].push_back(i);
            tree(_adj,mapp,i,current,_N);
        }
    }
}

void subtree(vector<int> & _size,map<int,vector<int>> & mapp,const int current,const int & _N){
    _size[current]=1;
    for (auto i : mapp[current]){
        subtree(_size,mapp,i,_N);
        _size[current] += _size[i];
    }
}




int main(){    
    freopen("input.txt", "rt", stdin);
    int N , M , Q;
    cin >> N >> M >> Q;

    map<int,vector<int>> mm;
    vector<int> size(N,0);
    map<int,vector<int>> adj;
    

    for(int i =1 ; i < N; i ++)
        mm[i] = vector<int>();
    
    for(int i =1 ; i < N; i ++){
        int i1,i2;
        cin >> i1 >> i2 ;
        adj[i1-1].push_back(i2-1);
        adj[i2-1].push_back(i1-1);
    }
    vector<int> sub;

    for(int i =0 ; i < Q ; i++){
        int k ;
        cin >> k;
        //cout << " k " << k ;
        sub.push_back(k);
        }

    
    tree(adj,mm,M-1,-1,N);
    subtree(size,mm,M-1,N);

    for (auto i : sub){
        cout << size[i-1] << '\n';
    }
    
       
    return 0;
}



/* 이거로 통과함
// 노드 수가 많아지면서 인접행렬을 만드는 경우에 메모리 부족이 일어나서 실패했었음
// 사실 루트부터 전부 확인할 필요는 없었던 것 같음

#include <iostream>
#include <vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std ;

void tree(map<int,vector<int>> & _adj,map<int,vector<int>>& mapp,const int current,const int parent,const int & _N){
    for(auto i : _adj[current]){
        if(i !=parent){
            mapp[current].push_back(i);
            tree(_adj,mapp,i,current,_N);
        }
    }
}

void subtree(vector<int> & _size,map<int,vector<int>> & mapp,const int current,const int & _N){
    _size[current]=1;
    for (auto i : mapp[current]){
        subtree(_size,mapp,i,_N);
        _size[current] += _size[i];
    }
}

int main(){    
//    freopen("input.txt", "rt", stdin);
    int N , M , Q;
    cin >> N >> M >> Q;

    map<int,vector<int>> mm;
    vector<int> size(N,0);
    map<int,vector<int>> adj;
    

    for(int i =1 ; i < N; i ++)
        mm[i] = vector<int>();
    
    for(int i =1 ; i < N; i ++){
        int i1,i2;
        cin >> i1 >> i2 ;
        adj[i1-1].push_back(i2-1);
        adj[i2-1].push_back(i1-1);
    }
    vector<int> sub;

    for(int i =0 ; i < Q ; i++){
        int k ;
        cin >> k;
        //cout << " k " << k ;
        sub.push_back(k);
        }

    
    tree(adj,mm,M-1,-1,N);
    subtree(size,mm,M-1,N);

    for (auto i : sub){
        cout << size[i-1] << '\n';
    }
    
       
    return 0;
}

*/









/*메모리 초과
#include <iostream>
#include <vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std ;


void tree(const vector<vector<int>> & mat,map<int,vector<int>>& mapp,const int current,const int parent,const int & _N){
    for(int i =0 ; i < _N ; i ++){
        if(mat[current][i]==1&& i !=parent){
            mapp[current].push_back(i);
            tree(mat,mapp,i,current,_N);
        }
    }
}

void subtree(vector<int> & _size,map<int,vector<int>> & mapp,const int current,const int & _N){
    _size[current]=1;
    for (auto i : mapp[current]){
        subtree(_size,mapp,i,_N);
        _size[current] += _size[i];
    }
}




int main(){    
    freopen("input.txt", "rt", stdin);
    int N , M , Q;
    cin >> N >> M >> Q;
    map<int,vector<int>> mm;
    vector<int> size(N,0);

    vector<vector<int>> vec(N,vector<int>(N,0));

    for(int i =1 ; i < N; i ++)
        mm[i] = vector<int>();
    
    for(int i =1 ; i < N; i ++){
        int i1,i2;
        cin >> i1 >> i2 ;
        vec[i1-1][i2-1]=1;
        vec[i2-1][i1-1]=1;
    }
    vector<int> sub;

    for(int i =0 ; i < Q ; i++){
        int k ;
        cin >> k;
        //cout << " k " << k ;
        sub.push_back(k);
        }

    
    tree(vec,mm,M-1,-1,N);
    subtree(size,mm,M-1,N);

    for (auto i : sub){
        cout << size[i-1] << '\n';
    }
    
       
    return 0;
}
*/ 