#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int t, id;

int dfs(int cur, vector<int> &visited, vector<int> &parent_arr, stack<int> &st, const vector<vector<int>> &graph, vector<vector<int>> &scc, vector<int> &group){
    parent_arr[cur] = ++id;
    st.push(cur);
    int parent = parent_arr[cur];
    
    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];
        
        if(parent_arr[next] == 0) parent = min(parent, dfs(next, visited, parent_arr, st, graph, scc, group));
        else if(!visited[next]) parent = min(parent, parent_arr[next]);
    }
    
    if(parent == parent_arr[cur]){
        vector<int> tmp;
        while(!st.empty()){
            int x = st.top();
            visited[x] = 1;
            tmp.push_back(x);
            group[x] = scc.size() + 1;
            st.pop();
            
            if(x == cur)
                break;
        }
        scc.push_back(tmp);
    }
    return parent;
}

void solve(){
    cin >> t;
    int n, m, x, y;
    while(t--){
        vector<vector<int>> graph, scc;
        vector<int> visited, parent_arr, group, cnt;
        stack<int> st;
        id = 0;
        cin >> n >> m;
        
        graph.resize(n+1);
        visited.resize(n+1, 0);
        parent_arr.resize(n+1, 0);
        group.resize(n+1);
        cnt.resize(n+1, 0);
        
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            graph[x].push_back(y);
        }
        
        for(int i = 1; i <= n; i++){
            if(parent_arr[i] == 0)
                dfs(i, visited, parent_arr, st, graph, scc, group);
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                int next = graph[i][j];
                
                if(group[i] != group[next]){
                    cnt[group[next]]++;
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= scc.size(); i++){
            if(cnt[i] == 0)
                res++;
        }
        
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}