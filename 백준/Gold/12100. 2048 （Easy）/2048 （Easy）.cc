#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res;
vector<vector<int>> board;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void init(){
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            cin >> board[i][j];
        }
    }
}

void move(vector<vector<int>> &next_board, int dir){
    if(dir == 0){
        for(int j = 0; j < n; j++){
            vector<int> col;
            for(int i = 0; i < n; i++){
                if(next_board[i][j] != 0)
                    col.push_back(next_board[i][j]);
            }
            
            vector<int> new_col;
            vector<int> merged = vector<int>(col.size(), 0);
            
            for(int i = 0; i < col.size(); i++){
                if(new_col.empty() || merged[new_col.size()-1] || new_col.back() != col[i]){
                    new_col.push_back(col[i]);
                }
                else{
                    new_col.back() *= 2;
                    merged[new_col.size()-1] = 1;
                }
            }
            
            for(int i = 0; i < n; i++){
                if(i < new_col.size())
                    next_board[i][j] = new_col[i];
                else
                    next_board[i][j] = 0;
            }
        }
    }
    else if(dir == 1){
         for(int j = 0; j < n; j++){
            vector<int> col;
            for(int i = n-1; i >= 0; i--){
                if(next_board[i][j] != 0)
                    col.push_back(next_board[i][j]);
            }
            
            vector<int> new_col;
            vector<int> merged = vector<int>(col.size(), 0);
            
            for(int i = 0; i < col.size(); i++){
                if(new_col.empty() || merged[new_col.size()-1] || new_col.back() != col[i]){
                    new_col.push_back(col[i]);
                }
                else{
                    new_col.back() *= 2;
                    merged[new_col.size()-1] = 1;
                }
            }
            
            for(int i = 0; i < n; i++){
                if(i < new_col.size())
                    next_board[n-1-i][j] = new_col[i];
                else
                    next_board[n-1-i][j] = 0;
            }
        }
    }
    else if(dir == 2){
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < n; j++){
                if(next_board[i][j] != 0)
                    row.push_back(next_board[i][j]);
            }
            
            vector<int> new_row;
            vector<int> merged = vector<int>(row.size(), 0);
            
            for(int i = 0; i < row.size(); i++){
                if(new_row.empty() || merged[new_row.size()-1] || new_row.back() != row[i]){
                    new_row.push_back(row[i]);
                }
                else{
                    new_row.back() *= 2;
                    merged[new_row.size()-1] = 1;
                }
            }
            
            for(int j = 0; j < n; j++){
                if(j < new_row.size())
                    next_board[i][j] = new_row[j];
                else
                    next_board[i][j] = 0;
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = n-1; j >= 0; j--){
                if(next_board[i][j] != 0)
                    row.push_back(next_board[i][j]);
            }
            
            vector<int> new_row;
            vector<int> merged = vector<int>(row.size(), 0);
            
            for(int i = 0; i < row.size(); i++){
                if(new_row.empty() || merged[new_row.size()-1] || new_row.back() != row[i]){
                    new_row.push_back(row[i]);
                }
                else{
                    new_row.back() *= 2;
                    merged[new_row.size()-1] = 1;
                }
            }
            
            for(int j = 0; j < n; j++){
                if(j < new_row.size())
                    next_board[i][n-1-j] = new_row[j];
                else
                    next_board[i][n-1-j] = 0;
            }
        }
    }
}

void dfs(vector<vector<int>> &next_board, int depth){
    if(depth == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res = max(res, next_board[i][j]);
            }
        }
        return;
    }
    
    for(int i = 0; i < 4; i++){
        vector<vector<int>> board_tmp = next_board;
        move(board_tmp, i);
        dfs(board_tmp, depth+1);
    }
}

void solve(){
    for(int i = 0; i < 4; i++){
        vector<vector<int>> board_tmp = board;
        move(board_tmp, i);
        dfs(board_tmp, 1);
    }
    
    cout << res;
}

int main() {
    init();
    solve();
    return 0;
}