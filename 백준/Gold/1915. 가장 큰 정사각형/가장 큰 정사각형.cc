#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001], squares[1001][1001];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            squares[i][j] = str[j] - '0';
            if(squares[i][j])
                dp[i][j] = 1;
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(squares[i][j])
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
            res = max(dp[i][j], res);
        }
    }
    cout << res * res;
    return 0;
}