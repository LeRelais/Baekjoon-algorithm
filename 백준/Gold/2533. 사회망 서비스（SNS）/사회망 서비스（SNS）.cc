#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, u, v;
vector<vector<int>> tree;
vector<vector<int>> dp;
void init(){
    cin >> n;
    tree.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

void make_tree(int cur, int parent){
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    
    for(int i = 0; i < tree[cur].size(); i++){
        int x = tree[cur][i];
        
        if(x != parent){
            make_tree(x, cur);
            
            dp[cur][0] += dp[x][1];
            dp[cur][1] += min(dp[x][0], dp[x][1]);
        }
    }
}

void solve(){
    make_tree(1, -1);
    
    cout << min(dp[1][0], dp[1][1]);
}

int main() {
    init();
    solve();
}