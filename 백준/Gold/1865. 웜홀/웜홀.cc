#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodes, t;

bool find_negative_cycle(vector<vector<pair<int, int>>> edges, int cur){
    vector<int> cnt;
    vector<long long> dist;
    vector<bool> used;
    used.resize(nodes+1, false);
    cnt.resize(nodes+1, 0);
    dist.resize(nodes+1, 1e18);
    queue<int> q;
    cnt[cur]++;
    q.push(cur);
    dist[cur] = 0;
    used[cur] = true;
    bool negative_cycle = false;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        used[x] = false;
        
        for(int i = 0; i < edges[x].size(); i++){
            int next = edges[x][i].first;
            int cost = edges[x][i].second;
            
            if(dist[next] > (long long)dist[x] + cost && dist[x] != 1e18){
                dist[next] = dist[x] + cost;
                
                if(!used[next]){
                    used[next] = true;
                    cnt[next]++;
                    q.push(next);
                    if(cnt[next] >= nodes){
                        negative_cycle = true;
                        break;
                    }
                }
            }
        }
        if(negative_cycle)
            break;
    }
    return negative_cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    int n, m, w, a, b, c;
    while(t--){
        cin >> n >> m >> w;
        nodes = n;
        vector<vector<pair<int, int>>> edges;
        edges.resize(n+1);
        
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            edges[a].push_back({b, c});
            edges[b].push_back({a, c});
        }
        for(int i = 0; i < w; i++){
            cin >> a >> b >> c;
            edges[a].push_back({b, -1 * c});
        }
        
        bool has_cycle = false;
        for(int i = 1; i <= n; i++){
            if(find_negative_cycle(edges, i)){
                has_cycle = true;
                break;
            }
        }
        if(has_cycle){
            cout << "YES" << '\n';
        }
        else
            cout << "NO" << '\n';
    }
    return 0;
}