#include <string>
#include <vector>
#include <iostream>

/*
예제 1부터 살펴보면 만약 1이 9앞에 있으면 1은 제거했을때보다 명백하게 작은 수가 된다
첫번째는 P 에 첫번째 원소 넣고 pass

P : 이전
T : 지금

2번째부터 
p=1
t=9
만약 p < t 이라면 p에 해당하는 원소를 체크리스트에 체크
p에 9넣고 다음

3번째
t=2
만약 p < t 이라면 p에 해당하는 원소를 체크리스트에 체크
이때 2가 더 작으므로 현재 t를 제외하지 않고 
p에 2를 넣고 다음

4번째
t=4
만약 p < t 이라면 p에 해당하는 원소를 체크리스트에 체크
이때 t가 4로 더 크므로 2를 제외함

* 종료마다 count 가 k와 동일한지 반복해서 점검

예제 3번

위와 마찬가지로
(숫자를 직접 보관하지 말고 인덱스로 number 안에서 검색)
p=4
p=4 t=1 -> 만약 count가 k보다 작으면 p=4를 유지하고 다음으로
p=4 t=7 -> 만약 count가 k보다 작으면 p=4를 체크해버리고 p에 새로 7을 넣어줌
p=7 t=7 -> 만약 count가 k보다 작으고 p=t로 p는 명백하게 숫자에 포함된다 p에 새로 7을 넣어줌
p

k만 충분하다면 만약 뒤에 갖고 있던 수보다 크다면 버릴 수 있음

즉, 앞에서 p=7이었고,


k=7으로 만들면 앞절자와 동일하게 진행되다가 
77까지 보유하다 8과 판단을 해서 8을 남겨야함 
-> 문자열을 줄여서 여러번 판단하면 되지 않을까?
-> 넣어놓고 판단하는 방법도 있지 않을까? 임시로 answer 문자열을 만들어 놓고 제거하기 제외할 수 있는 만큼

*/




using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    char prev ;
    for (auto i : number){
        
        
    }
    
    return answer;
}