#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[8][8][3], dist[8][8], n, m;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
        for (int k = 0; k < 3; ++k)
            dp[i][j][k] = 5000;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> dist[i][j];
        }
    }
    
    for(int k = 0; k < 3; k++){
        for(int i = 1; i <= m; i++){
            dp[1][i][k] = dist[1][i];
        }
    }
    
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j][0] = min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + dist[i][j];
            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + dist[i][j];
            dp[i][j][2] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + dist[i][j];
        }
    }
    
    
    // for(int i = 0; i < 3; i++){
    //     for(int y= 1; y <=n; y++){
    //         for(int x = 1; x <= m; x++){
    //             cout << dp[y][x][i] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl << endl;
    // }
    
    
    int res = 987654321;
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++)
            res = min(res, dp[n][j][i]);
    }
    
    cout << res;
    
    return 0;
}