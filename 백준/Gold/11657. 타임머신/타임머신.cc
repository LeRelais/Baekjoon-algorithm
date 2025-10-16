#include <iostream>
#include <vector>

using namespace std;

typedef struct _data{
    int from;
    int to;
    int cost;
} DATA;

vector<DATA> edges;
vector<int> parent, dist;
int n, m;

void init(){
    cin >> n >> m;
    parent.resize(n+1);
    dist.resize(n+1);
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    } 
    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        dist[i] = 987654321;
    }
    dist[1] = 0;
}

void solve(){
    for(int i = 1; i <= n-1; i++){
        bool updated = false;
        for(int j = 0; j < edges.size(); j++){
            int from = edges[j].from;
            int to = edges[j].to;
            int cost = edges[j].cost;
            if(dist[from] == 987654321)
                continue;
                
            if((long long)dist[from] + cost < dist[to]){
                dist[to] = dist[from]+cost;
                parent[to] = from;
                updated = true;
            }
        }
        if(!updated)
            break;
    }
    for(int i = 0; i < edges.size(); i++){
        int from = edges[i].from;
        int to = edges[i].to;
        int cost = edges[i].cost;
        if(dist[to] == 987654321)
            continue;
        if((long long)dist[from] + cost < dist[to]){
            cout << -1;
            return;
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(dist[i] == 987654321)
            cout << -1 <<'\n';
        else
            cout << dist[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}