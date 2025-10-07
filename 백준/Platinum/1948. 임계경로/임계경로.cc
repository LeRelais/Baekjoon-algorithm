#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m, a, b, t, s, e;
vector<int> degree, dp, res, visited;
vector<vector<pair<int, int>>> graph, r_graph;
map<pair<int, int>, int> edges;

void init(){
    cin >> n >> m;
    graph.resize(n+1);
    r_graph.resize(n+1);
    dp.resize(n+1, 0);
    visited.resize(n+1, 0);
    degree.resize(n+1);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        r_graph[b].push_back({a, -t});
        degree[b]++;
    }
    cin >> s >> e;
}

void find_path_num(){
    queue<int> q;
    q.push(e);

    int cnt = 0;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x == s)
            continue;
        
        for(int i = 0; i < r_graph[x].size(); i++){
            int nx = r_graph[x][i].first;
            //cout << x << ' ' << dp[x] << ' ' << nx << ' ' << dp[nx] << endl;
            if(dp[nx] == dp[x] + r_graph[x][i].second){
                edges[{x, nx}] = 1;
                if(!visited[nx]){
                    q.push(nx);
                    visited[nx] = 1;
                }
            }
        }
    }
}

void solve(){
    queue<int> q;
    
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            dp[i] = 0;
        }
    }
    
    q.push(s);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < graph[x].size(); i++){
            int nx = graph[x][i].first;
            degree[nx]--;
            dp[nx] = max(dp[nx], dp[x] + graph[x][i].second);
            if(degree[nx] == 0){
                q.push(nx);
            }
        }
    }
    
    find_path_num();
    cout << dp[e] << '\n' << edges.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
}