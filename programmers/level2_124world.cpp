#include <string>
#include <vector>

using namespace std;
// 10 -> 3 * 3 + 1
// 9  -> 3 * 2 + 3
// 4대신 3이라고 생각하기
// 1 2 3 11 12 13 
// 21 22 23 31

// 오른쪽부터 *1 *3 으로 하면 되는 듯
// 최대 n은 5억
// 한자리에서 최대로 가질 수 있는 수는 3
// 12 -> 4
// 41 42 
// 44 -> 3*3 + 3 * 1 -> 12 나누기 3 -> 4 => 

// 1 2 0 // 1 2 0 // 1 2 0 
// 11 42  12 44  111 13  112  14     15  5 114 3^2 3^1 3
// 16 121 17 122     124     6      0 - >  0 6 ->  2 
// 18 -> 1 2 4 ()  19 :1  4 1 -> 9 + 9 + 1
// 20 -> 1 4 2      21 -> 1 4 4 // 7 -> 2 -> 1 
// 규칙 3의 배수인 경우 3으로 한 번 나누어준 몫을 4진법으로 나타냄
// 규칙 3의 배수인 경우 맨 뒤에 4 붙여주고
// 


string solution(int n) {
    string answer = "";
    return answer;
}