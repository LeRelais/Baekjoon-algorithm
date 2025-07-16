#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
    int h, y;
    
    cin >> h >> y;
    
    dp[h] = h;
    
    for(int i = h; i <= h+y; i++){
        dp[i+1] = max(int(dp[i] * 1.05), dp[i+1]);
        dp[i+3] = max(int(dp[i] * 1.2), dp[i+3]);
        dp[i+5] = max(int(dp[i] * 1.35), dp[i+5]);
    }
    
    cout << dp[h+y];
    
    return 0;
}