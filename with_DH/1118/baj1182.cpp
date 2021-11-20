#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 조합을 구할 것인데
// 가장 앞의 원소부터 경우의 수를 기준 우삼각 원소만 확인할 것
// dfs
// 부분집합의 경우의 수가 엄청 많음 조기 종료 조건 필요함
// 정렬 조건 추가
// 정렬한 상태에서 따졌을때 어차피 특정 수 이후에 더한다고 해서 해가 되지 않기 때문\

// if 
void dfs(const vector<int> & _vec,int & ans,int  added,const int & criteria,const int & start,const int & size){
    cout << ans <<" "<< added << endl;
    if (added ==criteria){
        ans +=1;
        return;
    }else{
        for (int i = start ; i < size; i++){
        
        dfs(_vec,ans,added+_vec[i],criteria,start+1,size);
        
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
    sort(vec.begin(),vec.end());
    cout << vec[0] << endl;
    cout << N <<" " << S << endl;
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