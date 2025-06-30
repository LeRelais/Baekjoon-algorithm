#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int c, n, max_f;
vector<pair<int, int>> v;
int dp[1101];

void solve(){
    
    dp[0] = 0;
    
    for(int i = 1; i <= c+max_f; i++){
        for(int j = 0; j < v.size(); j++){
             //cout << i-v[j].second << endl;
            if(i-v[j].second >= 0 && dp[i] != 98765321){
                dp[i] = min(dp[i], dp[i-v[j].second] + v[j].first);
            }
        }
    }
    
    // for(int i = 1; i <= c+n; i++)
    //     cout << dp[i] << ' ';
    // cout << endl;
    
    int res_min = 98765321;
    
    for(int i = c; i <= c+max_f; i++)
        res_min = min(res_min, dp[i]);
    
    cout << res_min;
}

int main() {
    for(int i = 0; i < 1101; i++)
        dp[i] = 987654321;
    cin >> c >> n;
    
    int p, f;
    for(int i = 0; i < n; i++){
        cin >> p >> f;
        v.push_back({p,f});
        max_f = max(max_f, f);
        //dp[f] = p;
    }
    
    solve();
}