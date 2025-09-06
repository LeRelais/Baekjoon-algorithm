#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int dp[1000001], trace[1000001], n;
deque<int> dq;

void init(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        dp[i] = 987654321;
    }
}

void solve(){
    dp[1] = 0;
    
    for(int i = 1; i < n; i++){
        if(dp[i] + 1 < dp[i+1]){
            dp[i+1] = dp[i] + 1;
            trace[i+1] = i;
        }
        
        if(dp[i] + 1 < dp[i*2] && i * 2 <= n){
            dp[i*2] = dp[i] + 1;
            trace[i*2] = i; 
        }
        
        if(dp[i] + 1 < dp[i*3] && i * 3 <= n){
            dp[i*3] = dp[i] + 1;
            trace[i*3] = i; 
        }
    }
    
    int cur = n;
    
    while(cur != 0){
        dq.push_back(cur);
        cur = trace[cur];
    }
    
    cout << dp[n] << '\n';
    
    while(!dq.empty()){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();    
    solve();
}