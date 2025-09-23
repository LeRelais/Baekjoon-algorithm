#include <iostream>
#include <string>

using namespace std;

long long dp[5001];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    
    if(str[0] == '0')
    {
        cout << 0;
        return 0;
    }
    
    dp[0] = 1;
    for(int i = 1; i <= str.length(); i++){
        if(str[i-1] != '0')
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
    
        
        if(str[i-2] == '1'){
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
        }
        else if(str[i-2] == '2'){
            if(str[i-1] >= '0' && str[i-1] <= '6'){
                dp[i] = (dp[i] + dp[i-2]) % 1000000;
            }
        }
    }
    
    cout << dp[str.length()];
    return 0;
}