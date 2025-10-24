#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<string> board;
vector<vector<int>> dp;
vector<vector<bool>> visited; 

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool is_infinite = false;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    board.resize(N);
    dp.resize(N, vector<int>(M, 0)); 
    visited.resize(N, vector<bool>(M, false)); 
    
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
}

int dfs(int y, int x) {
    if (visited[y][x]) {
        is_infinite = true;
        return -1;
    }

    if (dp[y][x] > 0) {
        return dp[y][x];
    }

    visited[y][x] = true;
    
    int move_count = board[y][x] - '0';
    int max_moves = 0;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i] * move_count;
        int nx = x + dx[i] * move_count;

        if (ny >= 0 && ny < N && nx >= 0 && nx < M && board[ny][nx] != 'H') {
            int result = dfs(ny, nx);

            if (is_infinite) {
                visited[y][x] = false; 
                return -1;
            }
            
            max_moves = max(max_moves, result);
        }
    }

    visited[y][x] = false;  
    dp[y][x] = 1 + max_moves;
    return dp[y][x];
}

void solve() {
    int result = dfs(0, 0);

    if (is_infinite) {
        cout << -1 << '\n';
    } else {
        cout << result << '\n';
    }
}

int main() {
    init();
    solve();
    return 0;
}