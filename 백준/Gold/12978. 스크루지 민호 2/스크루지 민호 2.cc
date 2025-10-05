#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, u, v;
vector<vector<int>> graph;
vector<vector<int>> dp;

void init(){
    cin >> n;
    graph.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void make_tree(int cur, int parent){
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    
    for(int i = 0; i < graph[cur].size(); i++){
        int nx = graph[cur][i];
        
        if(nx != parent){
            make_tree(nx, cur);
            
            dp[cur][0] += dp[nx][1];
            dp[cur][1] += min(dp[nx][0], dp[nx][1]);
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