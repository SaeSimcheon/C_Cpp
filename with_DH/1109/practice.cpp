#include <string>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vec(n,1);
    vec[0]=0;
    for (int i=2; i <n/2+1;i++){
        for (int j= 2; j*i<=n;j++){
            vec[i*j-1]=0;
        }
    }
    return accumulate(vec.begin(),vec.end(),0);
}


#include <string>
#include <vector>
#include <iostream>
using namespace std;

string bin(int a, const int & give){
    string str = "";
    while (a!=0){
        str.insert(0,to_string(a%2)); // 앞에서 넣는 방법
        a/=2; 
    }
    for (int i = give-str.size(); i>0 ;i--){
        str.insert(0,"0");// 앞에서 넣는 방법
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i =0; i < n ; i++){
        string s1 = bin(arr1[i],n);
        string s2 = bin(arr2[i],n);
        string onestr= "";
        for (int j =0; j < n ; j++){
            if (s1[j]=='1'||s2[j]=='1')
                onestr +="#";
            else
                onestr += " ";
        }
        answer.push_back(onestr); // index로 접근하는 것은 core dumped 유발
    }
    
    return answer;
}