#include <iostream>

using namespace std;

int n, dp[200002], jumps[200002];

int main() {
    cin >> n;
    dp[n] = 1;
    
    for(int i = 1; i <= n; i++)
        cin >> jumps[i];
    
    for(int i = n-1; i >= 1; i--){
        if(!jumps[i]){
            dp[i] = dp[i+1]+1;
        }
        else{
            if(i+jumps[i]+1 > n)
                dp[i] = 1;
            else
                dp[i] = dp[i+jumps[i]+1]+1;
        }
    }
    
    for(int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
    
    return 0;
}