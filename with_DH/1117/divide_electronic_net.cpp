#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
using namespace std;

// tree가 특정 노드에서 부모 노드와 자른 연결을 자른 경우에 
// subtree를 이루고 그 개수를 파악하는 것이
// 인접노드 정보를 통한 tree 구성에서 쉽게 계산 될 수 있는 점을 이용하여
// 인접 노드 -> 트리 구성 -> 하위 트리 

void tree(map<int,vector<int>> & _adj,map<int,vector<int>> & _child ,const int & current,const int & parent){
    for (auto node : _adj[current]){
        if(node!=parent){
            _child[current].push_back(node);
            tree(_adj,_child,node,current);
        }
    }
}

void subtree(vector<int> & _size, map<int,vector<int>> & _child,const int & current){
    _size[current] =1;
    for (auto node : _child[current]){
        subtree(_size,_child,node);
        _size[current]+=_size[node];
    }
}

int solution(int n, vector<vector<int>> wires) {
    
    int answer = 101;
    int candidate = 0;
    map<int,vector<int>> adj;
    map<int,vector<int>> child;
    
    vector<int> size(n,0);
    for(auto avec : wires){
        adj[avec[0]-1].push_back(avec[1]-1);
        adj[avec[1]-1].push_back(avec[0]-1);
    }
    tree(adj,child,n-1,-1);
    subtree(size,child,n-1);
    
    
    for ( auto i : size){
        int candidate = abs(n-2*i);
        if (answer > candidate){
            answer = candidate;
        }
    }
        
    return answer;
}