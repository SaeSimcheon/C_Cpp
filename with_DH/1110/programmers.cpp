#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


// 키 조합을 가장 최소 개수인 1개부터 하나씩 늘려가되,
// 1개로 모든 row를 식별할 수 있는 경우는 최소성 조건 때문에 별도의 컬럼을 추가해서는 안 된다.
// 마찬가지로 2개로 후보키가 될 수 있는 경우는 별도의 컬럼을 추가해서 3개 조합이 되서는 안 된다.
// 위 언급한 두 조건에 따라서 컬럼 조합의 크기를 키울때 이전 크기에서 발견된 키는 제외한 집합을 탐색한다.
// ex/ 학번 <- 1개로 후보키 => 2개로 후보키가 되는 조건을 찾을때 전체 컬럼 집합에서 학번은
// 제외한다.


// 컬럼의 식별 가능 것은 어떻게? -> sql로 치면 distinct?

// stl 의 set을 이용할 수 있을까?

// 컬럼들 중 일부만 선택해서 비교하는 방법 만들어야 함 -> column subset


// 일단 set ss=set(relation.begin(),relation.end()); 이런 방식으로 vector -> set으로
// 적용은 가능함. 전부 확인해야한다는 단점 있음
// set에 push back ?
// 특정 컬럼만 추출해서 set을 적용했을때 개수가 적어지면 중복이 일어났다고 판단할 것임.





vector<vector<int>> combination(vector<int> vec,int number){
//
//vector<int> vec : A vector that consists of candidates
//int number : The number of a subset.
    vector<vector<int>> rtvector;
    // 만약 앞의 시행에서 일부가 제거 되었으면 어떻게 조합에 반영할 것인가?
    // 벡터 자료 형은 중간 원소 제거가 오래 걸리는데
    // 그리고 일단 가능은 한가?
    // -> 일단 외부에서 추려서 인풋으로 넣어준다고 생각하자
    vector<int>index;
    for (int i =0;i<number;i++)
        index.push_back(1);
    for (int i =0;i<vec.size()-number;i++)
        index.push_back(0);

    // 원리는 모르겠는데 sort 꼭 해야하네

    sort(index.begin(), index.end());


    
    do{
        vector<int> avec;
        /* index 벡터의 순서가 내부적으로 바뀜
        for (auto i : index)
            cout << i;
            cout << endl;
            */
        for (int i=0;i<index.size();i++){
            if(index[i]==1){
                avec.push_back(vec[i]);
            }
        }

        rtvector.push_back(avec);
    }while(next_permutation(index.begin(),index.end()));
    return rtvector;
}

vector<string> subset(const vector<int> vv ,const vector<string> vs){
    vector<string> rt;
    
    for (auto v : vv ){
        rt.push_back(vs[v]);
    }
    return rt;
}

int solution(vector<vector<string>> relation) {
    
    string test1 = "abab";
    bool bb =test1.find("123") == string::npos;
    
    cout << "test " << bb << endl; 
    
    
    int answer = 0;
    int col_num =relation[0].size(); 
    vector<int> indicator(col_num,0);
    
    vector<int> columns ;
    
    vector<string> answer_set;
    
    for (int i =0;i < col_num;i++)
        columns.push_back(i);
    
    for (int i =1 ; i <= col_num;i++){
        
        vector<vector<int>> zip = combination(columns,i);
        for (auto j : zip){
            vector<vector<string>> checker;
            
            for (auto l : relation){
                checker.push_back(subset(j,l));}
            
            set ss=set(checker.begin(),checker.end());   
            
            if (ss.size()==relation.size()){
                string can = "";
                
                for (auto jj : j)
                    can+= to_string(jj);
                cout << can <<endl;
                if (answer_set.size()==0){
                        answer+=1;
                        answer_set.push_back(can);
                }
                else{
                    int pass =0;
                    for (auto kk : answer_set){
                        int dep=0;
                        for (auto k : kk){
                            if (can.find(k)!=string::npos)
                                dep+=1;
                        }
                        if (kk.size()==dep){
                            pass =1;
                            break;}}
                    if (pass == 0){
                        answer+=1;
                        answer_set.push_back(can);}
                    }
                }
            }
                
        }
    cout <<endl;
    for (auto i : answer_set)
        cout << i<< " " <<endl;
    //cout << ss.size()<< endl;
    // next_permutation으로 조합을 만들어서 sub vector 만들 것임.
    // 특정 케이스 좀 자세하게 생각해야할 것 같은데, 만약 저 예제와 달리
    // 이름 전공 // 이름 학년 조합이 후보키가 가능하다면?
    // 남은 컬럼이 만드는 셋의 크기가 다음에 따질 조합보다 작은 경우 시행을 종료한다.
    
    return answer;
}

// 처음에 1819202528 에러

// 키 중복 안 되는 거 아니었음 나는 아예 이전 크기에서 선택되면 다음에 지워버렸는데 더 큰 크기에서
// 찾을 수 있었음

// 후보키들의 vector를 만들어서 그 중에 현재 만들 것들 중 적어도 하나를 포함하는 경우 제외해야함.