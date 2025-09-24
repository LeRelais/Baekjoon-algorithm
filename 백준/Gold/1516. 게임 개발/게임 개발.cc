#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<int> construct_t, degrees, total_t;
vector<vector<int>> relations;

void init(){
    cin >> n;
    
    construct_t.resize(n+1);
    degrees.resize(n+1);
    relations.resize(n+1);

    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> construct_t[i];
        while(1){
            cin >> tmp;
            if(tmp == -1)
                break;
            
            relations[tmp].push_back(i);
            degrees[i]++;
        }
    }
}

void solve(){
    queue<int> q;
    vector<int> res = vector<int>(n+1, 0);
    
    for(int i = 1; i <= n; i++){
        if(degrees[i] == 0){
            q.push(i);
            res[i] = construct_t[i];
        }
    }

    
    for(int i = 1; i <= n; i++){
        while(!q.empty()){
            int cur = q.front();
            q.pop();
        
            
            for(int x = 0; x < relations[cur].size(); x++){
                int tmp = relations[cur][x];
                
                res[tmp] = max(res[tmp], res[cur] + construct_t[tmp]);
                
                degrees[tmp]--;
                if(degrees[tmp] == 0)
                    q.push(tmp);

            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << res[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}