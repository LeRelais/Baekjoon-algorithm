#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, d, c;
vector<int> dist;
vector<vector<pair<int, int>>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

void init(){
    cin >> n >> d >> c;
    dist = vector<int>(n+1, 987654321);
    
    v = vector<vector<pair<int, int>>>(n+1);
    
    int a, b, s;
    for(int i = 0; i < d; i++){
        cin >> a >> b >> s;
        v[b].push_back({a, s});
    }
    
}

void solve(){
    dist[c] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, c});
    
    while(!q.empty()){
        int cur_time = q.top().first;
        int x = q.top().second;
        q.pop();
        
        if(cur_time > dist[x])
            continue;
        
        for(int i = 0; i < v[x].size(); i++){
            int nx = v[x][i].first;
            int infect_time = v[x][i].second;
            
            if(dist[nx] > dist[x] + infect_time){
                dist[nx] = dist[x] + infect_time;
                q.push({dist[nx], nx});
            }
        }
    }
    
    int max_t = 0;
    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        if(dist[i] != 987654321){
            cnt++;
            max_t = max(max_t, dist[i]);
        }
    }
    
    cout << cnt << ' ' << max_t << '\n';
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        init();
        solve();
    }
    return 0;
}