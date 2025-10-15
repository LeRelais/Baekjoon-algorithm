#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
vector<vector<int>> city, visited;

typedef struct _data{
    int y;
    int x;
    int cost;
} DATA;

struct cmp{
  bool operator()(const DATA &a, const DATA &b){
      return a.cost > b.cost;
  }  
};

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void init(){
    cin >> m >> n;
    city.resize(m, vector<int>(n, 0));
    visited.resize(m, vector<int>(n, 987654321));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> city[i][j];
        }
    }
}

void solve(){
    if(city[0][0] == -1){
        cout << -1;
        return;
    }
    priority_queue<DATA, vector<DATA>, cmp> q;
    q.push({0,0,city[0][0]});
    visited[0][0] = city[0][0];
    
    while(!q.empty()){
        int y = q.top().y;
        int x = q.top().x;
        int cost = q.top().cost;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < m && nx >= 0 && nx < n){
                if(cost + city[ny][nx] < visited[ny][nx] && city[ny][nx] != -1){
                    visited[ny][nx] = cost + city[ny][nx];
                    q.push({ny, nx, visited[ny][nx]});
                }
            }
        }
    }
    if(visited[m-1][n-1] == 987654321)
        cout << -1;
    else
        cout << visited[m-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}