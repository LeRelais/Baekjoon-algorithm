#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, u, v;
vector<int> w, res;
vector<vector<int>> graph, dp, choice;

void init(){
    cin >> n;
    w.resize(n+1);
    graph.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void make_tree(int cur, int parent){
    dp[cur][0] = 0;
    dp[cur][1] = w[cur];
    
    for(int i = 0; i < graph[cur].size(); i++){
        int nx = graph[cur][i];
        
        if(nx != parent){
            make_tree(nx, cur);
            
            dp[cur][0] += max(dp[nx][0], dp[nx][1]);
            
            dp[cur][1] += dp[nx][0];
        }
    }
}

void find_set(int cur, int parent, int state){
    if(state == 1){
        res.push_back(cur);
        
        for(int i = 0; i < graph[cur].size(); i++){
            int nx = graph[cur][i];
            
            if(nx != parent){
                find_set(nx, cur, 0);
            }
        }
    }
    else{
        for(int i = 0; i < graph[cur].size(); i++){
            int nx = graph[cur][i];
            
            if(nx != parent){
                int next_state = (dp[nx][1] > dp[nx][0]) ? 1 : 0;
                find_set(nx, cur, next_state);
            }
        }
    }
}

void solve(){
    make_tree(1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    int state = dp[1][0] > dp[1][1] ? 0 : 1;
    
    find_set(1, -1, state);
    
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
}