#include <iostream>
#include <vector>

using namespace std;

int n, t, res;

void dfs(int cur, const vector<int> &graph, vector<int> &visited){
    visited[cur] = 1;
    
    if(visited[graph[cur]])
        return;
    
    dfs(graph[cur], graph, visited);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        res = 0;
        vector<int> visited(n+1, 0);
        vector<int> graph(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            cin >> graph[i];
        }
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i, graph, visited);
                res++;
            }
        }
        
        cout << res << '\n';
    }
    return 0;
}