#include <iostream>
#include <vector>

using namespace std;

// 조합을 구할 것인데
// 가장 앞의 원소부터 경우의 수를 기준 우삼각 원소만 확인할 것
// dfs

void dfs(const vector<int> & _vec,int & ans,int  added,const int & criteria,const int & start,const int & size){
    if (added ==criteria){
        ans +=1;
    }
    else{
        for (int i = start ; i < size; i++){
            added += _vec[i] ;
            dfs(_vec,ans,added,criteria,start+1,size);
            added -= _vec[i] ;
        }
    }
}




int main(){
    freopen("input.txt", "rt", stdin);
    int answer =0;
    int N, S;
    cin >> N >> S;
    vector<int> vec ; 
    for (int i =0 ; i < N; i++){
        int get ;
        cin >> get;
        vec.push_back(get);
    }
    dfs(vec,answer,0,S,0,N);
    cout << answer ;

    return 0;
}



/* 채점은 되는데 시간 초과가 뜸 커팅룰 만들어야할듯
#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<int> & _vec,int & ans,int  added,const int & criteria,const int & start,const int & size){
    if (added ==criteria){
        ans +=1;
    }
    else{
        for (int i = start ; i < size; i++){
            added += _vec[i] ;
            dfs(_vec,ans,added,criteria,start+1,size);
            added -= _vec[i] ;
        }
    }
}




int main(){
    int answer =0;
    int N, S;
    cin >> N >> S;
    vector<int> vec ; 
    for (int i =0 ; i < N; i++){
        int get ;
        cin >> get;
        vec.push_back(get);
    }
    dfs(vec,answer,0,S,0,N);
    cout << answer ;

    return 0;
}
*/