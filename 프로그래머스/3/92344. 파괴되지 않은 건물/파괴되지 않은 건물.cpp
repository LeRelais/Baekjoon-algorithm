#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> pre_sum(board.size()+1, vector<int>(board[0].size()+1, 0));
    
    for(int i = 0; i < skill.size(); i++){
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if(skill[i][0] == 1){
            degree *= -1;
        }
        
        pre_sum[r1][c1] += degree;
        pre_sum[r2+1][c1] -= degree;
        pre_sum[r1][c2+1] -= degree;
        pre_sum[r2+1][c2+1] += degree;
    }
    
    for(int i = 0; i <= board.size(); i++){
        for(int j = 1; j <= board[0].size(); j++){
            pre_sum[i][j] += pre_sum[i][j-1];
        }
    }
    
    for(int j = 0; j <= board[0].size(); j++){
        for(int i = 1; i <= board.size(); i++){
            pre_sum[i][j] += pre_sum[i-1][j];
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] + pre_sum[i][j] >= 1)
                answer++;
        }
    }
    return answer;
}