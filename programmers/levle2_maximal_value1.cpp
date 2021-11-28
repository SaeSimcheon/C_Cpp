#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 주어진 숫자 배열을 이용해서 가장 큰 수를 만드는 방법
// 숫자 정렬을 이용해야겠다고 생각 했었음
// 11/28 실패 (signal: aborted (core dumped)) 이거는 왜 생기는 거임 ??
// 0 -> 0000 1 -> 1111 10 -> 1011


// 도움을 받음 https://programmers.co.kr/questions/23775 -> 천까지만 값제한이 있어서 예제 자체는 잘못 써 있음
// 왜일까 ??
// 나는 모두 4개 길이로 만들어서 비교했었는데, 첫자리 숫자를 뒤에 추가해주는 방법으로 비교 했었다
// 302 30로 만들 수 있는  수는 30302와 30230임 30302가 제일 큼
// 내가 했던 방식대로 하면 302 30 -> 3023 3033이므로 30302가 됨(문제 없음)


// 개수를 맞춰서 정수로 비교하면 계속 틀림
// 그런데 길이를 3배만큼 늘려서 문자열로 비교하면 문제가 안 됨

// 천 이하 조건을 무시하는 테스트 케이스가 있는 것이 아닐까 ??




bool cmp(const vector<string> & a ,const vector<string> & b){
    if(a[1]!=b[1]) return a[1]>b[1] ;
    else {
        //return a[1].size() <b[1].size();
        return false;
    }
    
}



vector<vector<string>> make_2d(const vector<int> & N){
    vector<vector<string>> M ;
    
    for (auto a: N){
        vector<string> given;
        string A ="" ;
        string S =to_string(a);
        
        given.push_back(S);
        for (int i =0 ; i < 4 ; i ++){
            for (auto ii :S)
                A+=ii;
        }
        // 1000 vs 9 
        // 9999 1 1111 1000
        // 999면 9999가 됨
        // 9면 ? 9999 -> 이거면 우선순위가 어떻게 되어야하지 ? 9 999 999 9 차이가 없음
        // 4 -> 4444 
        // 4-1 = 3 : 0 1 2 // 
        
        
        
        given.push_back(A);
        //cout <<"A "<< A << endl;
        M.push_back(given);
    }
    
    
    return M;
}


string solution(vector<int> numbers) {
    string answer = "";

    
    vector<vector<string>> test=make_2d(numbers);
    //bool tts = stoi("0000")<stoi("1111");
    //cout << tts;
    
    stable_sort(test.begin(),test.end(),cmp);
    
    
    for (auto i : test){
        answer +=i[0];
    }
    
    if (answer[0] == '0')
        return "0";
    /*
    int bb=stoi(answer);
    
    string a = to_string(bb);
    */
    
    
    return answer;
}








//아래 코드가 내가 틀린 코드
//예상인데 1~6에서 천 이하 조건을 어기는 경우가 있는 것 같음

/*


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 주어진 숫자 배열을 이용해서 가장 큰 수를 만드는 방법
// 숫자 정렬을 이용해야겠다고 생각 했었음
// 11/28 실패 (signal: aborted (core dumped)) 이거는 왜 생기는 거임 ??
// 0 -> 0000 1 -> 1111 10 -> 1011

bool cmp(const vector<string> & a ,const vector<string> & b){
    if(stoi(a[1])!=stoi(b[1])) return stoi(a[1])>stoi(b[1]);
    else {
        //return a[1].size() <b[1].size();
        return false;
    }
    
}



vector<vector<string>> make_2d(const vector<int> & N){
    vector<vector<string>> M ;
    
    for (auto a: N){
        vector<string> given;
        string A ="" ;
        string S =to_string(a);
        
        given.push_back(S);
        for (int i =0 ; i < S.size() ; i ++){
            A=A+ S[i];
        }
        // 1000 vs 9 
        // 9999 1 1111 1000
        // 999면 9999가 됨
        // 9면 ? 9999 -> 이거면 우선순위가 어떻게 되어야하지 ? 9 999 999 9 차이가 없음
        // 4 -> 4444 
        // 4-1 = 3 : 0 1 2 // 
        
        for ( int j =0 ; j <4-S.size() ; j++){
            A=A+ S[0];
        }
        
        given.push_back(A);
        //cout <<"A "<< A << endl;
        M.push_back(given);
    }
    
    
    return M;
}


string solution(vector<int> numbers) {
    string answer = "";

    
    vector<vector<string>> test=make_2d(numbers);
    //bool tts = stoi("0000")<stoi("1111");
    //cout << tts;
    
    stable_sort(test.begin(),test.end(),cmp);
    
    
    for (auto i : test){
        answer +=i[0];
    }
    
    if (answer[0] == '0')
        return "0";

    int bb=stoi(answer);
    
    string a = to_string(bb);
    
    
    
    return answer;
}

*/