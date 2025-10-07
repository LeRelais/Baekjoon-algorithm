#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b;
vector<int> population;
vector<vector<int>> dp, graph;


void init(){
    cin >> n;
    population.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    graph.resize(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> population[i];
    }
    
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void make_tree(int cur, int parent){
    dp[cur][0] = 0;
    dp[cur][1] = population[cur];
    
    for(int i = 0; i < graph[cur].size(); i++){
        int nx = graph[cur][i];
        
        if(nx != parent){
            make_tree(nx, cur);
            dp[cur][0] += max(dp[nx][0], dp[nx][1]);
            dp[cur][1] += dp[nx][0];
        }
    }
}

void solve(){
    make_tree(1, -1);
    
    cout << max(dp[1][0], dp[1][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
}