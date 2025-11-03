#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

void solve(){
    cin >> t;
    int n, m, val;
    while(t--){
        cin >> n;
        vector<int> v1, v2;
        v1.resize(n);
        for(int i = 0; i < n; i++){
            cin >> v1[i];
        }
        sort(v1.begin(), v1.end());
        cin >> m;
        
        for(int i = 0; i < m; i++){
            cin >> val;
            
            if(binary_search(v1.begin(), v1.end(), val))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}