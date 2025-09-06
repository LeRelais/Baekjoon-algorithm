#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT pow(2,32) - 1;

int t, n;

void solve(){
    cin >> n;
    vector<int> coins(n);
    
    int coin;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    int m;
    cin >> m;
    
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= m; j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    
    cout << dp[m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}