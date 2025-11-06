#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> graph;
vector<vector<long long>> dist;

typedef struct _data{
    int x;
    int cnt;
    long long cost;
}DATA;

struct cmp{
    bool operator()(const DATA &a, const DATA &b){
        return a.cost > b.cost;
    }
};

void init(){
    cin >> n >> m >> k;
    graph.resize(n+1);
    dist.resize(n+1, vector<long long>(k+1, 987654321987654321LL));
    int u, v, d;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }
}

void solve(){
    dist[1][0] = 0;
    priority_queue<DATA, vector<DATA>, cmp> pq;
    pq.push({1, 0, 0LL});
    
    while(!pq.empty()){
        int x = pq.top().x;
        int cnt = pq.top().cnt;
        long long cost = pq.top().cost;
        pq.pop();
        
        if(dist[x][cnt] < cost)
            continue;
        
        for(int i = 0; i < graph[x].size(); i++){
            int next = graph[x][i].first;
            int n_cost = graph[x][i].second;
            
            if(dist[next][cnt] > n_cost + cost){
                dist[next][cnt] = cost + n_cost;
                pq.push({next, cnt, dist[next][cnt]});
            }
            
            if(cnt+1 <= k){
                if(dist[next][cnt+1] > cost){
                    dist[next][cnt+1] = cost;
                    pq.push({next, cnt+1, dist[next][cnt+1]});
                }
            }
        }
    }
    
    long long res = 987654321987654321LL;
    
    for(int i = 0; i <= k; i++){
        res = min(res, dist[n][i]);
    }
    
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}