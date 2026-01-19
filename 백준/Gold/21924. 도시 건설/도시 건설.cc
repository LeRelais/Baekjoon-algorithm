#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

typedef struct _data{
    int c;
    int from;
    int to;
}DATA;

vector<DATA> v;
vector<int> parent;

bool cmp(const DATA &a, const DATA &b){
    return a.c < b.c;
}

int get_parent(int x){
    if(x == parent[x])
        return x;
    return parent[x] = get_parent(parent[x]);
}

void combine(int a, int b){
    int pa = get_parent(a);
    int pb = get_parent(b);
    
    if(pa != pb){
        if(pa > pb){
            parent[pa] = pb;
        }
        else{
            parent[pb] = pa;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int a, b, c;
    long long total_c = 0, min_cost = 0;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        total_c += c;
        v.push_back({c, a, b});
    }
    
    parent = vector<int>(n+1, 0);    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    
    sort(v.begin(), v.end(), cmp);
    vector<DATA> edges;
    
    for(int i = 0; i < v.size(); i++){
        if(edges.size() == n-1){
            break;
        }
        
        int cost = v[i].c;
        int from = v[i].from;
        int to = v[i].to;
        
        if(get_parent(from) != get_parent(to)){
            combine(from, to);
            edges.push_back(v[i]);
            min_cost += cost;
        }
    }

    if(edges.size() != n-1){
        cout << -1;
    }
    else{
        cout << total_c - min_cost;
    }
    return 0;
}