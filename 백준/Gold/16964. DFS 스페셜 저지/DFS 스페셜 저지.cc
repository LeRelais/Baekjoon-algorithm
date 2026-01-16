#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001], order, v;
int n, priority[100001], visited[100001];

bool cmp(const int &a, const int &b){
    return priority[a] < priority[b];
}

void dfs(int cur){
    if(visited[cur])
        return;
    
    visited[cur] = 1;
    v.push_back(cur);
    
    for(int i = 0; i < graph[cur].size(); i++){
        dfs(graph[cur][i]);   
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 0 ; i < n; i++){
        cin >> a;
        order.push_back(a);
        priority[a] = i;
    }
    
    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end(), cmp);
    }
    
    dfs(1);
    
    int flag = 1;
    for(int i = 0; i < n; i++){
       if(v[i] != order[i]){
           flag = 0;
           break;
       }
    }
    
    cout << flag;
    return 0;
}