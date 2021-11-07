// 3진뒤
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    string ast="";
    while (n!=0){
        ast += to_string(n%3);
        n = n/3;
    }
    cout << ast <<endl;
    for (int i =0; i <ast.size();i++){
        answer += pow(3,ast.size()-i-1)*(ast[i]-'0');
    }
    
    return answer;
}


// 폰켓몬
#include <vector>
#include <iostream>
#include <set>
#include <numeric>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int select = nums.size()/2;
    set<int> s(nums.begin(),nums.end());
    
    if (s.size() <= select)
        return s.size();
    else
        return select;
}

// 실패율

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool ftn(const vector<double> & a , const vector<double> & b){
    if (a[1] == b[1])
        return a[0]<b[0];
    return a[1] > b[1];
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N,0);
    vector<int> remain(N,0);
    vector<int> trace(N,0);
    
    for (auto ss : stages){
        if (ss > N){
            for (int i =0 ; i < N;i++){
                trace[i]+=1;
            }
            continue;
        }
        for (int j =0 ; j < ss;j++){
            trace[j]+=1;   
        }
        remain[ss-1]+=1;
    }
    vector<vector<double>> prob(N,vector<double>(2,0));
    
    for (int i =0; i < N;i++){
        if (trace[i] ==0)
            prob[i][1] = 0 ;
        else
            prob[i][1]=((double)remain[i])/((double)trace[i]);
        prob[i][0] =i;
    }
    sort(prob.begin(),prob.end(),ftn);
    for (int i = 0 ; i < N ; i ++)
        answer[i]= prob[i][0] +1;
    
    
    
    return answer;
}


// 약수

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ftn(const int & a){
    int give =0;
    for (int i = 1; i<a+1;i++){
        if (a % i ==0)
            give+=1;
    }
    return give;
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left;i <right +1;i ++){
        cout << i << ' ' <<endl;
        if (ftn(i)%2==0){
            answer+= i;
        }else{
            answer-= i;
        }
    }
        
    
    return answer;
}



// 체육복


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> vv(n,0);
    for (auto j : lost)
        vv[j-1] =-1;
    for (auto j : reserve)
        vv[j-1]+=1;
    
    for (int i =0 ; i < vv.size();i++){
        if (vv[i] <= 0)
            continue;
        if (i==0&&vv[i+1]==-1){
            vv[i] =0;
            vv[i+1]=0;
            continue ;}
        if(i==vv.size()-1&&vv[i-1]==-1){
            vv[i] =0;
            vv[i-1]=0;
            continue ;}
        if (vv[i-1]==-1){
            vv[i] =0;
            vv[i-1]=0;
            continue ;
        }
        if (vv[i+1]==-1){
            vv[i] =0;
            vv[i+1]=0;
            continue ;
        }
        vv[i] =0;
    }
    
    return n +accumulate(vv.begin(),vv.end(),0);
}