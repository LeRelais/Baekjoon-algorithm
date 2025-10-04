#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<vector<int>> tree;
vector<int> sub_tree;

int make_tree(int node, int parent){
    sub_tree[node] = 1;
    
    for(int i = 0; i < tree[node].size(); i++){
        if(tree[node][i] != parent){
            sub_tree[node] += make_tree(tree[node][i], node);
        }
    }
    
    return sub_tree[node];
}

void init(){
    cin >> n >> r >> q;
    tree.resize(n+1);
    sub_tree.resize(n+1, 0);
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    make_tree(r, -1);
}



void solve(){
    int tmp;
    for(int i = 0; i < q; i++){
        cin >> tmp;
        cout << sub_tree[tmp] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
}