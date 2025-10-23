#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<vector<long long>>> dp;

void init(){
    cin >> n;
    board.resize(n+1, vector<int>(n+1));
    dp.resize(n+1, vector<vector<long long>>(n+1, vector<long long>(3,0))); //0 가로, 1 세로, 2 대각선
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    }
}

void solve(){
    dp[1][2][0] = 1;
    for(int i = 2; i <= n; i++){
        if(board[1][i] == 1)
            break;
        dp[1][i][0] = 1;
    }
for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) { 

            if (i == 1 && j == 2) continue; 
        
            if (board[i][j] == 1) continue; 

            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];

            if (i > 1) { 
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
            }

            if (i > 1 && board[i-1][j] == 0 && board[i][j-1] == 0) { 
                dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
    }
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}