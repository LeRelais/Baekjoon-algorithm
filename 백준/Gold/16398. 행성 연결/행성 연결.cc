#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[1001][1001], n, parent[1001];

typedef struct _data{
    int cost;
    int from;
    int to;
}DATA;

vector<DATA> v;

bool cmp(const DATA &a, const DATA &b){
    return a.cost < b.cost;
}

int find_parent(int x){
    if(parent[x] == x)
        return x;
    
    return parent[x] = find_parent(parent[x]);
}

void join_points(int a, int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    
    if(pa > pb){
        parent[pa] = pb;
    }
    else if(pa < pb){
        parent[pb] = pa;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
            if(i < j){
                v.push_back({graph[i][j], i, j});
            }
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    vector<DATA> res;
    long long min_cost = 0;
    for(int i = 0; i < v.size(); i++){
        if(res.size() == n-1)
            break;
        
        int cost = v[i].cost;
        int from = v[i].from;
        int to = v[i].to;
        
        if(find_parent(from) != find_parent(to)){
            join_points(from, to);
            res.push_back(v[i]);
            min_cost += cost;
        }
    }
    
    cout << min_cost;
}