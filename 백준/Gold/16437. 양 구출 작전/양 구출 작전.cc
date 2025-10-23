#include <iostream>
#include <vector>
using namespace std;

int n;
long long num;
vector<int> animals;
vector<vector<pair<int, int>>> tree;

void init(){
    cin >> n;
    tree.resize(n+1);
    animals.resize(n+1);
    char animal;
    long long cnt; 
    int tmp;
    for(int i = 0; i < n-1; i++){
        cin >> animal >> cnt >> tmp;
        if(animal == 'W'){
            tree[tmp].push_back({i+2, -1 * cnt});
            animals[i+2] = -1 * cnt;
        }
        else{
            tree[tmp].push_back({i+2, cnt});
            animals[i+2] = cnt;
        }
    }
}

long long dfs(int cur){
    if(tree[cur].empty()){
        if(animals[cur] > 0)
            return animals[cur];
        return 0;
    }
    
    long long res = 0;
    for(int i = 0; i < tree[cur].size(); i++){
        res += dfs(tree[cur][i].first);
    }
    
    if(animals[cur] + res <= 0)
        return 0;
    return (long long)animals[cur] + res;
}

void solve(){
    long long res = 0;
    for(int i = 0; i < tree[1].size(); i++){
        res += dfs(tree[1][i].first);
    }
    
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}