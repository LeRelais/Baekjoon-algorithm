#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int o_cnt = 0, x_cnt = 0, o_win = 0, x_win = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].length(); j++){
            if(board[i][j] == 'O')
                o_cnt++;
            else if(board[i][j] == 'X')
                x_cnt++;
        }
    }
    
    if(x_cnt > o_cnt)
        return 0;
    
    if(o_cnt + 2 <= x_cnt || o_cnt >= x_cnt + 2)
        return 0;
    
    if((board[0][0] == 'O' && board[0][1] == 'O' &&  board[0][2] == 'O') ||
       (board[1][0] == 'O' && board[1][1] == 'O' &&  board[1][2] == 'O') ||
       (board[2][0] == 'O' && board[2][1] == 'O' &&  board[2][2] == 'O') ||
       (board[0][0] == 'O' && board[1][0] == 'O' &&  board[2][0] == 'O') ||
       (board[0][1] == 'O' && board[1][1] == 'O' &&  board[2][1] == 'O') ||
       (board[0][2] == 'O' && board[1][2] == 'O' &&  board[2][2] == 'O') || 
       (board[0][0] == 'O' && board[1][1] == 'O' &&  board[2][2] == 'O') ||
       (board[0][2] == 'O' && board[1][1] == 'O' &&  board[2][0] == 'O')
      ){
        o_win = 1;
    }
    
    if((board[0][0] == 'X' && board[0][1] == 'X' &&  board[0][2] == 'X') ||
       (board[1][0] == 'X' && board[1][1] == 'X' &&  board[1][2] == 'X') ||
       (board[2][0] == 'X' && board[2][1] == 'X' &&  board[2][2] == 'X') ||
       (board[0][0] == 'X' && board[1][0] == 'X' &&  board[2][0] == 'X') ||
       (board[0][1] == 'X' && board[1][1] == 'X' &&  board[2][1] == 'X') ||
       (board[0][2] == 'X' && board[1][2] == 'X' &&  board[2][2] == 'X') || 
       (board[0][0] == 'X' && board[1][1] == 'X' &&  board[2][2] == 'X') ||
       (board[0][2] == 'X' && board[1][1] == 'X' &&  board[2][0] == 'X')
      ){
        x_win = 1;
    }
    
    if(o_win && x_win)
        return 0;
    
    if(o_win){
        if(o_cnt != x_cnt+1)
            return 0;
    }
    
    if(x_win){
        if(x_cnt != o_cnt)
            return 0;
    }
    return answer;
}