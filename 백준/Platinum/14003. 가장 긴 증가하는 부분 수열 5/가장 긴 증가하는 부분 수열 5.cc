#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> seq, pos, lis;

void init(){
    cin >> n;
    seq.resize(n);
    pos.resize(n, -1);
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
}

void solve(){
    int max_len = 0, start_len;
    for(int i = 0; i < n; i++){
        int val = seq[i];
        auto it = lower_bound(lis.begin(), lis.end(), val);
        int idx = it - lis.begin();
        
        if(it == lis.end()){
            lis.push_back(val);
        }
        else
            *it = val;
        pos[i] = idx;
        
        if(idx+1 > max_len){
            max_len = idx;
        }
    }
    vector<int> used(n, 0);
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(pos[i] == max_len){
            used[i] = 1;
            cnt++;
            max_len--;
        }
        if(max_len < 0)
            break;
    }
    
    cout << cnt << '\n';
    for(int i = 0; i < n; i++){
        if(used[i])
            cout << seq[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}