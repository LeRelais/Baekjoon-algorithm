#include <iostream>
#include <vector>

using namespace std;

int n, a, b, parent[50001], level[50001], t, m;
vector<int> graph[50001];

void init(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void make_tree(int node, int pnode){
    parent[node] = pnode;
    level[node] = level[pnode]+1;
    
    for(int i = 0; i < graph[node].size(); i++){
        int child = graph[node][i];
        
        if(child == pnode)
            continue;
            
        make_tree(child, node);
    }
}

void find_lca(int a, int b){
    int f_node = a, s_node = b, f_level = level[a], s_level = level[b];
    
    while(f_level != s_level){
        if(f_level > s_level){
            f_node = parent[f_node];
            f_level = level[f_node];
        }
        else if(f_level < s_level){
            s_node = parent[s_node];
            s_level = level[s_node];
        }
    }
    
    while(f_node != s_node){
        f_node = parent[f_node];
        s_node = parent[s_node];
    }
    
    cout << f_node << '\n';
}

void solve(){
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        find_lca(a, b);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    init();
    make_tree(1, 0);
    solve();
    return 0;
}