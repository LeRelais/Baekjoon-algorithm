#include <iostream>

using namespace std;

int dp[10001][4], t, n;

int main() {
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for(int i = 4; i <= 10000; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
        
    }
    
    cin >> t;
    
    while(t--){
        int res = 0;
        cin >> n;
        for(int i = 1; i <= 3; i++)
            res += dp[n][i];
    
        cout << res << '\n';
    }
    return 0;
}