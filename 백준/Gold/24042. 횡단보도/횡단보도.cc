#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<long long> dist;
int n, m;

void init(){
    cin >> n >> m;
    adj.resize(n+1);
    dist.resize(n+1, 987654321987654321LL);
    
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
}

void solve(){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        long long cur_time = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cur_time)
            continue;
        
        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].first;
            int time_interval = adj[cur][i].second;
            long long wait_time = (time_interval - (cur_time % m) +  m) % m;
            
            if(dist[next] > dist[cur] + wait_time + 1){
                dist[next] = dist[cur] + wait_time + 1;
                pq.push({dist[next], next});
            }
        }
    }
    cout << dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}