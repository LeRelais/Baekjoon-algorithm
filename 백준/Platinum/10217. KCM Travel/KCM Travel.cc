#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int t, n, m, k, u, v, c, d;

typedef struct _data{
    int x;
    int cost;
    int dist;
}DATA;

struct cmp{
    bool operator()(const DATA &a, const DATA &b){
        return a.dist > b.dist;
    }
};

bool compareEdges(const DATA &a, const DATA &b) {
    return a.dist < b.dist;
}

string search(const vector<vector<DATA>> &arr, vector<vector<int>> &dist){
    priority_queue<DATA, vector<DATA>, cmp> pq;
    pq.push({1, 0, 0});
    dist[1][0] = 0;
    int min_dist = 987654321;
    
    while(!pq.empty()){
        int cur = pq.top().x;
        int c_cost = pq.top().cost;
        int c_dist = pq.top().dist;
        pq.pop();
        
        if(min_dist <= c_dist)
            continue;
        
        if(dist[cur][c_cost] < c_dist)
            continue;
        
        if(cur == n){
            min_dist = min(c_dist, min_dist);
            continue;
        }
        
        for(int i = 0; i < arr[cur].size(); i++){
            int next = arr[cur][i].x;
            int n_cost = arr[cur][i].cost;
            int n_dist = arr[cur][i].dist;
            
            int new_cost = c_cost + n_cost;
            int new_dist = c_dist + n_dist;
            
            if(new_cost <= m){
                if(dist[next][new_cost] > new_dist){
                    dist[next][new_cost] = new_dist;
                    if (new_dist < min_dist) {
                        pq.push({next, new_cost, new_dist});
                    }
                }
            }
        }
    }
    
    if(min_dist != 987654321)
        return to_string(min_dist);
    return "Poor KCM";
}

void solve(){
    cin >> t;
    
    while(t--){
        cin >> n >> m >> k;
        vector<vector<DATA>> arr;
        vector<vector<int>> dist;
        arr.resize(n+1);
        dist.resize(n+1, vector<int>(m+1,987654321));
        
        for(int i = 0; i < k; i++){
            cin >> u >> v >> c >> d;
            arr[u].push_back({v, c, d});
        }
        
        for (int i = 1; i <= n; ++i) {
            sort(arr[i].begin(), arr[i].end(), compareEdges);
        }
        
        string res = search(arr, dist);
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}