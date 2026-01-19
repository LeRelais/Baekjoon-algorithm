#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;
long long dp[101][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    dp[0][v[0]] = 1;
    for(int i = 1; i < n-1; i++){
        for(int j = 0; j <= 20; j++){
            if(dp[i-1][j] == 0) continue;
            
            if(j + v[i] <= 20){
                dp[i][j+v[i]] += dp[i-1][j];
            }
            if(j - v[i] >= 0){
                dp[i][j-v[i]] += dp[i-1][j];
            }
        }
    }
    
    cout << dp[n-2][v[v.size()-1]];
    return 0;
}