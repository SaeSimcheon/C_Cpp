#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    map<int,int> mMap;
    map<int,int> check;
    
    for(int i=0 ; i < board.size();i++){
        for (int j=0 ; j < board.size();j++){
            if (board[i][j] !=0 && mMap[j] < board.size()-i){
                mMap[j] = board.size()-i;
            }
        }
    }
    
    vector<int> stack ;
    for (int i :moves){
        int height;
        height = mMap[i-1] - check[i-1];
        //cout <<height <<endl;
        //cout<<"moves "<< i << "mMap "<<mMap[i-1]<<"check "<< check[i-1] <<endl;
        if (height ==0)
            continue;
        
        if (stack.size()==0)
            stack.push_back(board[board.size() - height][i-1]);
        else{
            if (stack[stack.size()-1] ==board[board.size() - height][i-1]){
                stack.pop_back();
                answer+=2;
                }
            else
                stack.push_back(board[board.size() - height][i-1]);
        }
        check[i-1] +=1;
    }
    
    
    return answer;
    }