#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, dist, node;
vector<vector<pair<int, int>>> tree;
vector<bool> used;
void init(){
    cin >> n;
    tree.resize(n+1);
    int a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a;
        while(1){
            cin >> b;
            if(b == -1)
                break;
            
            cin >> c;
            tree[a].push_back({b, c});
            tree[b].push_back({a, c});
        }
    }
}

void dfs(int cur, int cur_dist){
    used[cur] = true;
    
    if(cur_dist > dist){
        dist = cur_dist;
        node = cur;
    }
    
    for(int i = 0; i < tree[cur].size(); i++){
        int next = tree[cur][i].first;
        int nl = tree[cur][i].second;
        
        if(!used[next]){
            used[next] = true;
            dfs(next, cur_dist + nl);
        }
    }
}

void solve(){
    used.resize(n+1, false);
    dfs(1, 0);
    for(int i = 0; i <= n; i++)
        used[i] = false;
    used[node] = true;
    dist = 0;
    dfs(node, 0);
    cout << dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}