#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> door_pos;
vector<vector<char>> house;
typedef struct _data{
    int y;
    int x;
    int cnt;
    int dir;
} DATA;
int dist[51][51][4], n;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void init(){
    cin >> n;
    string tmp;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++)
                dist[i][j][k] = 987654321;
        }
    }
    
    house.resize(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        cin >> tmp;
        for(int j = 0; j < n; j++){
            house[i][j] = tmp[j];
            if(house[i][j] == '#')
                door_pos.push_back({i,j});
        }
    }
}

bool check(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= n)
        return false;
    if(house[y][x] == '*')
        return false;
    return true;
}

struct cmp{
    bool operator()(const DATA &a, const DATA &b){
        return a.cnt > b.cnt;
    }
};

void solve(){
    vector<DATA> res;
    priority_queue<DATA, vector<DATA>, cmp> q;
    for(int i = 0; i < 4; i++){
        q.push({door_pos[0].first, door_pos[0].second, 0, i});
        dist[door_pos[0].first][door_pos[0].second][i] = 0;
    }
    
    //q.push({door_pos[0].first, door_pos[0].second, 0, 2});
    
    while(!q.empty()){
        DATA cur = q.top();
        q.pop();
        
        if(dist[cur.y][cur.x][cur.dir] < cur.cnt)
            continue;
        
        if(cur.y == door_pos[1].first && cur.x == door_pos[1].second){
            cout << cur.cnt;
            break;
        }
        
        int ny = cur.y + dy[cur.dir];
        int nx = cur.x + dx[cur.dir];
        
        
        if(check(ny, nx)){
            if(cur.cnt < dist[ny][nx][cur.dir]){
                dist[ny][nx][cur.dir] = cur.cnt;
                q.push({ny,nx,cur.cnt, cur.dir});
            }
        }
        
         if(house[cur.y][cur.x] == '!'){
                int dir_l = (cur.dir + 3) % 4;
                if(dist[cur.y][cur.x][dir_l] > cur.cnt+1){
                    q.push({cur.y, cur.x, cur.cnt+1, dir_l});
                }
                
                int dir_r = (cur.dir + 1) % 4;
                if(dist[cur.y][cur.x][dir_r] > cur.cnt+1){
                    q.push({cur.y, cur.x, cur.cnt+1, dir_r});
                }
            }
    }
}

int main() {
    init();
    solve();
    return 0;
}