#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> dp;
vector<int> arr;
int t, w;

void init(){
    cin >> t >> w;
    dp.resize(t+1, vector<vector<int>>(w+1, vector<int>(3, -987654321)));
    int tmp;
    arr.push_back(-1);
    for(int i = 0; i < t; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    dp[0][0][1] = 0;
    
    for(int i = 1; i <= t; i++){
        int pos = arr[i];
        dp[i][0][1] = dp[i-1][0][1] + (pos == 1);
        for(int j = 1; j <= w; j++){
            for(int k = 1; k <= 2; k++){
                dp[i][j][k] = max(max(dp[i][j][k], dp[i-1][j][k] + (pos == k)), dp[i-1][j-1][3-k] + (pos == k));
            }
        }
    }
    
    int res = 0;
    
    for(int i = 0; i <= w; i++){
        for(int j = 1; j <= 2; j++){
            res = max(res, dp[t][i][j]);
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    return 0;
}