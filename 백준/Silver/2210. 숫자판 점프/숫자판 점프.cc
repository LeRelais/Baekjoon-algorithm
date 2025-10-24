#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> visited, board;
vector<int> comb;
set<string> s;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init(){
    board.resize(5, vector<int>(5));
    visited.resize(5, vector<int>(5, 0));
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j];
        }
    }
}

void dfs(int col, int row, vector<int> &tmp){
    if(tmp.size() == 6){
        string str = "";
        for(int i = 0; i < tmp.size(); i++){
            str += tmp[i] + '0';
        }
        s.insert(str);
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = col + dy[i];
        int nx = row + dx[i];
        
        if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5){

                tmp.push_back(board[ny][nx]);
                dfs(ny, nx, tmp);
                tmp.pop_back();
        }
    }
}

void solve(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
                comb.push_back(board[i][j]);
                dfs(i, j, comb);
                comb.pop_back();
        }
    }
    cout << s.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}