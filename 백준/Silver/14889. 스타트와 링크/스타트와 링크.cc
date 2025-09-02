#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s[21][21], used[21], res = 987654321;
vector<int> team_s;
void init(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> s[i][j];
        }
    }
}

void find_min_diff(vector<int> &a, vector<int> &b){
    int sum_a = 0, sum_b = 0;
    
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(i == j) continue;
            sum_a += s[a[i]][a[j]];
        }
    }
    
    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(i == j) continue;
            sum_b += s[b[i]][b[j]];
        }
    }
    
    res = min(res, abs(sum_a-sum_b));
}

void add_teammate(int idx){
    if(team_s.size() == n/2){
        vector<int> team_l;
        
        for(int i = 1; i <= n; i++){
            if(!used[i])
                team_l.push_back(i);
        }
        
        find_min_diff(team_s, team_l);
        
        return;
    }
    
    for(int i = idx+1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            team_s.push_back(i);
            add_teammate(i);
            team_s.pop_back();
            used[i] = 0;
        }        
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            team_s.push_back(i);
            add_teammate(i);
            team_s.pop_back();
            used[i] = 0;
        }        
    }
    
    cout << res;
}

int main() {
    init();
    solve();
}