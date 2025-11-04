#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int graph[401][401];

void init(){
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 987654321;
        }
    }
    
    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        graph[a][b] = 1;
    }
}

void solve(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][k] != 987654321 && graph[k][j] != 987654321){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    
    int s, a, b;
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> a >> b;
        bool is_before, is_after;
        if(graph[a][b] != 987654321){
            cout << -1 << '\n';
            continue;
        }
        if(graph[b][a] != 987654321){
            cout << 1 << '\n';
            continue;
        }
        
        cout << 0 << '\n';
            
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}