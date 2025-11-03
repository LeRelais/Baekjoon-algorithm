#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, a, b, c;
vector<vector<pair<int, int>>> graph;
vector<int> sanity, dist;

typedef struct _data{
    int san;
    int cost;
    int x;
}DATA;

struct cmp{
  bool operator()(const DATA &a, const DATA &b){
      return a.cost > b.cost;
  }  
};

void init(){
    cin >> n >> m >> a >> b >> c;
    int from, to, value;
    graph.resize(n+1);
    dist.resize(n+1, 987654321);
    sanity.resize(c+1, 987654321);
    for(int i = 0; i < n; i++){
        cin >> from >> to >> value;
        graph[from].push_back({to, value});
    }    
}

void solve(){
    priority_queue<DATA, vector<DATA>, cmp> pq;
    pq.push({0,0,a});
    int res = 987654321;
    while(!pq.empty()){
        int san = pq.top().san;
        int cost = pq.top().cost;
        int x = pq.top().x;
        pq.pop();
        
        if(x == b){
            res = min(res, san);
            continue;
        }
        
        for(int i = 0; i < graph[x].size(); i++){
            int next = graph[x][i].first;
            int n_cost = graph[x][i].second;
            
            if(cost + n_cost <= c){
                dist[next] = cost + n_cost;
                int n_san = max(san, n_cost);
                pq.push({n_san, dist[next], next});
            }
        }
    }
    
    if(res == 987654321)
        cout << -1;
    else
        cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}