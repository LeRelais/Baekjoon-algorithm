#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<vector<int>>> visited;

int n, m;

typedef struct _data{
    int y;
    int x;
    int f;
    int t;
}DATA;

struct cmp{
    bool operator()(const DATA &a, const DATA &b){
        return a.t > b.t;
    }
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init(){
    cin >> n >> m;
    v.resize(n, vector<int>(n));
    visited.resize(n, vector<vector<int>>(n, vector<int>(2, 987654321)));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
}

int get_wait_time(int cur_time, int period){
    if(cur_time % period == 0)
        return 0;
    int next_multiple = ((cur_time / period) + 1) * period;
    return next_multiple - cur_time;
}

void solve(){
    priority_queue<DATA, vector<DATA>, cmp> q;
    visited[0][0][0] = 0;
    q.push({0,0,0,0});
    
    while(!q.empty()){
        int y = q.top().y;
        int x = q.top().x;
        int f = q.top().f;
        int t = q.top().t;
        q.pop();
        
        if(visited[y][x][f] < t)
            continue;
            
        if(y == n-1 && x == n-1){
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(v[ny][nx] == 1){
                    int nt = t + 1;
                    int nf = f;
                    
                    if(visited[ny][nx][nf] > nt){
                        visited[ny][nx][nf] = nt;
                        q.push({ny, nx, nf, nt});
                    }
                }
                else if(v[ny][nx] > 1){
                    if(v[y][x] != 1)
                        continue;
                    
                    int nt = get_wait_time(t+1, v[ny][nx]) + 1 + t;
                    int nf = f;
                    
                    if(visited[ny][nx][nf] > nt){
                        visited[ny][nx][nf] = nt;
                        q.push({ny, nx, nf, nt});
                    }
                }
                else if(v[ny][nx] == 0 && f == 0){
                    if(v[y][x] != 1)
                        continue;
                        
                    int nf = 1;
                    int nt = get_wait_time(t+1, m) + 1 + t;
                    if(visited[ny][nx][nf] > nt){
                        visited[ny][nx][nf] = nt;
                        q.push({ny, nx, nf, nt});
                    }
                }
                else if(v[ny][nx] == 0 && f == 1)
                    continue;
            }
        }
    }
    cout << min(visited[n-1][n-1][0], visited[n-1][n-1][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}