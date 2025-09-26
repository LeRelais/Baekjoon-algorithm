#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _line{
    int a;
    int b;
} LINE;

bool cmp (const LINE &a, const LINE &b){
    return a.a < b.a;
}

int n;

void solve(){
    cin >> n;
    
    vector<LINE> lines(n);
    
    for(int i = 0; i < n; i++){
        cin >> lines[i].a >> lines[i].b;
    }
    
    sort(lines.begin(), lines.end(), cmp);
    
    vector<int> seq_b(n);
    for(int i = 0; i < n; i++)
        seq_b[i] = lines[i].b;
    
    vector<int> dp(n+1, 1);
    
    int max_cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(seq_b[j] < seq_b[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_cnt = max(max_cnt, dp[i]);
    }
    
    cout << n - max_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}