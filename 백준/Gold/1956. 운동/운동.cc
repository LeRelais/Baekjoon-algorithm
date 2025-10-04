#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int v, e, a, b, c;

vector<vector<int>> edge;

void init(){
    cin >> v >> e;
    edge.resize(v+1, vector<int>(v+1, 987654321));
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        edge[a][b] = c;
    }
}

void solve(){
    for(int i = 1; i <= v; i++){
        for(int j = 1 ; j <= v; j++){
            for(int k = 1; k <= v; k++){
                edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);
            }
        }
    }
    
    int res = 987654321;
    for(int i = 1; i <= v; i++){
        res = min(res, edge[i][i]);
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