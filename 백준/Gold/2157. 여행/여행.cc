#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data{
    int from;
    int to;
    int score;
} DATA;

vector<DATA> graph;
vector<vector<int>> dp;
int from, to, score;

int n, m, k;

bool cmp(const DATA &a, const DATA &b){
    if(a.from > b.from)
        return false;
    if(a.from == b.from){
        if(a.to > b.to){
            return false;
        }
    }
    return true;
}

void init(){
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++){
        cin >> from >> to >> score;
        graph.push_back({from, to, score});    
    }
    
    sort(graph.begin(), graph.end(), cmp);
}

void solve(){
    dp.resize(n+1, vector<int>(m+1));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }
    
    dp[1][1] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int x = 0; x < graph.size(); x++){
            int from = graph[x].from;
            int to = graph[x].to;
            int score = graph[x].score;
            
            if(from > to)
                continue;
            
            if(i == to){
                for(int j = 1; j < m; j++){
                    if(dp[from][j] != -1){
                        dp[to][j+1] = max(dp[to][j+1],dp[from][j] + score);
                    }
                }
            }
        }
    }
    
    int res = -1;
    for(int i = 1; i <= m; i++){
        res = max(res, dp[n][i]);
    }
    
    cout << res;
}

int main() {
    init();    
    solve();
}