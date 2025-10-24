#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, v, e;
bool is_bipartite;

void init(){
    cin >> t;
}

void bfs(int cur, int color, vector<vector<int>> v, vector<int> &visited){
    visited[cur] = color;
    queue<int> q;
    q.push(cur);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < v[x].size(); i++){
            int next = v[x][i];
            
            if(visited[next] == 0){
                visited[next] = visited[x] * -1;
                q.push(next);
            }
            else if(visited[next] + visited[x] != 0){
                is_bipartite = false;
                break;
            }
        }
        
        if(!is_bipartite)
            break;
    }
}

void solve(){
    int a, b;
    while(t--){
        cin >> v >> e;
        vector<vector<int>> arr;
        vector<int> visited;
        arr.resize(v+1);
        visited.resize(v+1, 0);
        is_bipartite = true;
        
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i = 1; i <= v; i++){
            if(visited[i] == 0){
                bfs(i, 1, arr, visited);
            }
            
            if(!is_bipartite)
                break;
        }
        
        if(is_bipartite)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}