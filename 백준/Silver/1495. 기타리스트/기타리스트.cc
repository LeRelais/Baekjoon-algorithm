#include <iostream>
#include <vector>

using namespace std;

bool dp[51][1001];
vector<int> v;
int n, s, m;

void init(){
    cin >> n >> s >> m;
    dp[0][s] = true;
}

void solve(){
    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        for(int j = 0; j <= m; j++){
            if(j-tmp >= 0 && dp[i-1][j-tmp]){
                dp[i][j] = true;
            }
            if(j+tmp <= m && dp[i-1][j+tmp])
                dp[i][j] = true;
        }
    }
    int res = -1;
    
    for(int i = 0; i <= m; i++){
        if(dp[n][i]){
            res = i;
        }
    }
    
    cout << res;
}

int main() {
    init();
    solve();
    return 0;
}