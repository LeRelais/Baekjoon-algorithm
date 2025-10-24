#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int v, e, a, b, id;
vector<vector<int>> graph, scc;
vector<int> parent_arr, visited;
stack<int> st;

void init(){
    cin >> v >> e;
    graph.resize(v+1);
    parent_arr.resize(v+1, 0);
    visited.resize(v+1, 0);
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
}

int dfs(int cur){
    parent_arr[cur] = ++id;
    st.push(cur);
    int parent = parent_arr[cur];
    
    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];
        
        if(parent_arr[next] == 0) parent = min(parent, dfs(next));
        else if(!visited[next]) parent = min(parent, parent_arr[next]);
    }
    
    if(parent == parent_arr[cur]){
        vector<int> tmp;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            tmp.push_back(x);
            visited[x] = 1;
            if(x == cur)
                break;
        }
        sort(tmp.begin(), tmp.end());
        tmp.push_back(-1);
        scc.push_back(tmp);
    }
    return parent;
}

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[0] < b[0];
}

void solve(){
    for(int i = 1; i <= v; i++){
        if(parent_arr[i] == 0)
            dfs(i);
    }
    sort(scc.begin(), scc.end(), cmp);
    cout << scc.size() << '\n';
    for(int i = 0; i < scc.size(); i++){
        for(int j = 0; j < scc[i].size(); j++){
            cout << scc[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}