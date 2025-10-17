#include <iostream>
#include <vector>

using namespace std;

int n, t, k, s;
vector<int> hours, score;
vector<vector<int>> dp;

void init(){
    cin >> n >> t;
    hours.resize(n+1);
    score.resize(n+1);
    dp.resize(n+1, vector<int>(t+1, 0));
    for(int i = 1; i <= n; i++){
        cin >> hours[i] >> score[i];
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            if(j - hours[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-hours[i]] + score[i]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[n][t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}