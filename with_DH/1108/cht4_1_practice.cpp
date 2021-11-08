#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
//functor 함수 객체
// operator()를 오버로드한 것
struct cmp {
int integer ;
cmp(int _integer){
    this->integer = _integer;
}
bool operator() (const string & a,const string & b){
    if (a[integer] == b[integer])
        return a < b;
    return a[integer] < b[integer];
}
};

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    //이거도 되고(이게 더 내가 알고 있는 거에서 이해가는 형태)
    //struct cmp pp=cmp(n);
    //sort(strings.begin(),strings.end(),pp);
    // pp -> pp(x, y )->pp.operator()(x,y) ;; https://blog.hexabrain.net/267 의 .operator() 검색
    //이거도 됨
    sort(strings.begin(),strings.end(),cmp(n));
    
    return strings;
}

*/



vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(),strings.end(),[n](const string & a,const string & b){
        if (a[n] == b[n])
            return a < b;
        return a[n] < b[n];
        
    });
    
    return strings;
}


#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> buff;
    int This = 0;
    for (auto a : dartResult){
        switch(a){
            case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '0':
                if (This ==1&& a =='0')
                    This= 10;
                else 
                    This = a - '0';
                break;
            case '*':
                if (buff.size() ==1){
                    buff[buff.size() -1 ] *=2;
                    break;}
                else{
                    buff[buff.size() -2 ] *=2;
                    buff[buff.size() -1 ] *=2;
                }
                break;
            case '#':
                buff[buff.size() -1 ] *=-1;
                break;
            case 'S':
                buff.push_back(pow(This,1));
                This =0;
                break;
            case 'D':
                buff.push_back(pow(This,2));
                This =0;
                break;
            case 'T':
                buff.push_back(pow(This,3));
                This =0;
                break;
                
        }
    }
    
    return answer + accumulate(buff.begin(),buff.end(),0);
}
