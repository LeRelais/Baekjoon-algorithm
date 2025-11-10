#include <iostream>
#include <vector>

using namespace std;

int parent[1000001];

int getParent(int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = getParent(parent[n]);
}

void connect(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);
    
    if(pa >= pb){
        parent[pa] = pb;
    }
    else{
        parent[pb] = pa;
    }
}

void solve(){
    int t, n, k, a, b, m;
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        cin >> n >> k;
        
        for(int j = 0; j < n; j++){
            parent[j] = j;
        }
        
        for(int j = 0; j < k; j++){
            cin >> a >> b;
            connect(a, b);
        }
        
        cin >> m;
        cout << "Scenario " << i << ":\n";
        for(int j = 0; j < m; j++){
            cin >> a >> b;
            if(getParent(a) == getParent(b)){
                cout << 1 << '\n';
            }
            else
                cout << 0 << '\n';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}