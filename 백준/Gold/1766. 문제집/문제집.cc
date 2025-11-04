#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> pre_cnt;
vector<vector<int>> after;
int n, m;

void init(){
    cin >> n >> m;
    pre_cnt.resize(n+1, 0);
    after.resize(n+1);
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        after[a].push_back(b);
        pre_cnt[b]++;
    }
}

void solve(){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    vector<int> used = vector<int>(n+1, 0);
    
    for(int i = 1; i <= n; i++){
        if(pre_cnt[i] == 0)
            pq.push(i);
    }
    
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        
        cout << x << ' ';
        
        // if(pq.empty())
        //     break;
        
        for(int i = 0; i < after[x].size(); i++){
            int next = after[x][i];
            pre_cnt[next]--;
            
            if(pre_cnt[next] == 0){
                pq.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}