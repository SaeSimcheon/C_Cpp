#include <iostream>
#include <vector>
using namespace std;
// M을 넣어줄 것
// N으로 ch 를 만들어서 체크해서 중복 피할 것
// dfs 아래에 무엇이 오는가 ? = 위 스택이 없어졌을때 무엇이 실행되는가? -> 체크리스트 1로 찍었던 것을 수정해서 보낼 것이다.
// 언제 어디서 리턴되는가 ? M을 줄여서 보내고 0인 경우 return 할 것이다.
// 반복문 안에서 print할 것이므로 return 직전에 따로 안 할 것이며,
// 

// 다시 00:37 위에서 잘못된 것
// 반복문 안에서 출력하면 1개를 기준으로 나머지 경우의 수가 표현 됨
// 방금 한 것 오류 : M ==0 안에서 한 번에 다 출력했는데 이런 경우에는 check만 보고 반복문을 통해서 출력되기 때문에 
// 순서대로 나옴 4 3을 출력해야 하는데 

// 3 4 가 나옴

// 대안으로 문자열에 추가해서 출력하는 것을 생각해봄

/* 12:37
void dfs(vector<int> check,int M ,const int & N){
    if ( M == 0){
        for (int i =0; i < N ; i ++){
            if (check[i]==1)
                cout << i+1 << ' ';}
        cout << endl;
        return ;
    }else{
        for (int i =0; i < N ; i ++){
            if (check[i]==0){
                check[i]=1;
                dfs(check,M-1,N);
                check[i]=0;
            }
        }
        
    }
    
}

*/
// 1:14 왜 느린지 고민해보면 
// 문자열 concat 할때 느릴 수 있고
// 불필요하게 조건을 따지고 있을 수도 있음

// char 고정길이 벡터로 만들어서 제공해보기로 했음
// 길이는 N의 2배

// 참조자가 시간에 영향을 끼치지 않을까라는 생각에 바꿀 수 있는 것은 참조자로 바꿈 -> 크게 영향을 끼치지는 않는듯


// 결국 아래 코드가 답이 되었음

// '\n'보다 endl;이 버퍼문제로 더 느리다고 함 https://www.acmicpc.net/board/view/51788
#include<string>
void dfs(vector<int> & check, string  ans,int M ,const int & N){
    if ( M == 0){
            cout << ans <<'\n';
        return ;
    }else{
        for (int i =0; i < N ; i ++){
            if (check[i]==0){
                check[i]=1;
                dfs(check,ans+to_string(i+1)+' ',M-1,N);
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
    vector<char> answer(N*2,' ');
    
    //cout << answer[0] <<endl;
    
    dfs(vec,"",M,N);
    
    
    
    
    return 0;
}


/* 1:06 이거 시간초과 뜨는데 왜 그런지 이해 안 감

#include <iostream>
#include <vector>
#include<string>
using namespace std;

void dfs(vector<int> check, string ans,int M ,const int & N){
    if ( M == 0){
        cout << ans <<endl;
        return ;
    }else{
        for (int i =0; i < N ; i ++){
            if (check[i]==0){
                check[i]=1;
                dfs(check,ans+to_string(i+1)+" ",M-1,N);
                check[i]=0;
            }
        }   
    }
}


int main(){
    int N , M ;
    cin >> N >> M ;
    vector<int> vec(N,0);
        
    dfs(vec,"",M,N);
   
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include<string>
using namespace std;

void dfs(vector<int> check, string ans,int M ,const int & N){
    if ( M == 0){
        cout << ans <<'\n';
        return ;
    }else{
        for (int i =0; i < N ; i ++){
            if (check[i]==0){
                check[i]=1;
                dfs(check,ans+to_string(i+1)+" ",M-1,N);
                check[i]=0;
            }
        }   
    }
}


int main(){
    int N , M ;
    cin >> N >> M ;
    vector<int> vec(N,0);
        
    dfs(vec,"",M,N);
   
    return 0;
}

*/