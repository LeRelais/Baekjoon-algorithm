#include <iostream>
#include <algorithm>

using namespace std;

int graph[101][101], n, m;

void init(){
    cin >> n >> m;
    int a, b;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = 987654321;
        }
    }
    
    for(int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    for(int i = 0; i < m; i++){
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
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(graph[i][j] != 987654321 || graph[j][i] != 987654321)
                cnt++;
        }
        cout << n - cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}