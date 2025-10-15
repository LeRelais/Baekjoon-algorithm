#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct _line{
    int a;
    int b;
    int num;
}LINE;
vector<LINE> lines;

bool cmp(const LINE &a, const LINE &b){
    return a.a < b.a;
}

void init(){
    vector<int> from, to;
    cin >> n;
    from.resize(n+1);
    to.resize(n+1);
    int tmp;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        from[tmp] = i+1;
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        to[tmp] = i+1;
    }
    
    for(int i = 1; i <= n; i++){
        lines.push_back({from[i], to[i], i});
    }
    
    sort(lines.begin(), lines.end(), cmp);
}

void solve(){
    vector<int> dp(n, 1);
    vector<int> pre(n, -1); 
    int res = 0, idx;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(lines[i].b > lines[j].b){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
        }
        if (dp[i] > res) {
            res = dp[i];
            idx = i;
        }
    }
    
    vector<int> switches;
    while(idx != -1){
        switches.push_back(lines[idx].num);
        idx = pre[idx];
    }
    cout << res << '\n';
    sort(switches.begin(), switches.end());
    for(int i = 0; i < switches.size(); i++){
        cout << switches[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}