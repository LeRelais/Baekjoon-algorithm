#include <iostream>
#include <vector>

using namespace std;

vector<int> health, joy;
vector<vector<int>> dp;
int n;

void init(){
    cin >> n;
    int tmp;
    dp.resize(n+1, vector<int>(101, 0));
    health.push_back(-1);
    joy.push_back(-1);
    for(int i = 0; i < n; i++){
        cin >> tmp;
        health.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        joy.push_back(tmp);
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 100; j++){
            if(j-health[i] > 0){
                dp[i][j] = max(dp[i-1][j-health[i]] + joy[i], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[n][100];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}