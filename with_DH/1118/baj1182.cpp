#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 조합을 구할 것인데
// 가장 앞의 원소부터 경우의 수를 기준 우삼각 원소만 확인할 것
// dfs


// 결국 아래가 답이 됐는데 기존의 풀이의 문제점은 부분집합을 종료할 조건을 안 만들었음
// 예를 들면 -4 -4 -3 -3 ... 인 수열이 있으면

// 답이 -7이면
// -4 -3 만 갖는 수열과 -4 -3 -3인 수열 후자의 경우에서 수열을 -4 -3까지 만들고
// 위의 조건문에서 판단해버리는 바람에 틀림
// 그래서 else에서 i의 판단을 size+1 전까지 즉, size까지 허용한다
// start는 매번 현재 탐색중인 index를 갖는데
// start가 만약 size+1 즉, 이전 스택에서 size의 탐색이고 i+1로 인해 size+1을 입력 받은 구문에 해당한다




void dfs(const vector<int> & _vec,int & ans,int  added,const int & criteria,const int & start,const int & size){
    if (start==size+1 && added ==criteria){
        ans +=1;
    }
    else{
        for (int i = start ; i < size+1; i++){
            if (i == size){
                if (start==0) // 이 조건을 따로둔 이유는 added를 0으로 초기화 하고 시작했기 때문에 만약 start 0 즉, 첫 원소 대입시에
                    // size가 선택되면 아무것도 안 들어감 초깃값으로 인해 해가 하나 더 체크되는 것을 방지 => 아예 다르게 초기화 하는 것이
                    // 좋지 않았을까?
                    return;
                dfs(_vec,ans,added,criteria,i+1,size);
            }else{
                dfs(_vec,ans,added+_vec[i],criteria,i+1,size);
            }
            
            
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