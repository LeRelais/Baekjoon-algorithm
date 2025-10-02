#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct _data{
    int y;
    int x;
    int dist;
} DATA;

vector<vector<int>> area, pass_map;
vector<pair<int, int>> start_pos, end_pos;
int n, m, i_fuel, start_y, start_x;
queue<DATA> q;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

struct cmp{
    bool operator()(const DATA &a, const DATA &b){
        if(a.dist < b.dist)
            return false;
        else if(a.dist == b.dist){
            if(a.y < b.y){
                return false;
            }
            else if(a.y == b.y){
                if(a.x < b.x){
                    return false;
                }
            }
        }
        return true;
    }
};

bool check(int y, int x){
    if(y < 1 || x < 1 || y > n || x > n)
        return false;
    if(area[y][x] == 1)
        return false;
    return true;
}

void init(){
    cin >> n >> m >> i_fuel;
    area.resize(n+1);
    pass_map.resize(n+1);
    
    for(int i = 0; i <= n; i++){
        area[i].resize(n+1);
        pass_map[i].resize(n+1);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> area[i][j];
            pass_map[i][j] = 0;
        }
    }
    
    cin >> start_y >> start_x;
    
    int y1, x1, y2, x2;
    for(int i = 0; i < m; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        start_pos.push_back({y1, x1});
        end_pos.push_back({y2, x2});
        pass_map[y1][x1] = i+1;
    }
}

DATA find_passenger(){
    priority_queue<DATA, vector<DATA>, cmp> pq;

    vector<vector<int>> pass;
    pass.resize(n+1);
    for(int i = 0; i <= n; i++)
        pass[i].resize(n+1);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           pass[i][j] = 0;
        }
    }
    
    queue<DATA> bfs_q;
    bfs_q.push({start_y, start_x, 0});
    pass[start_y][start_x] = 1;
    
    while(!bfs_q.empty()){
        int y = bfs_q.front().y;
        int x = bfs_q.front().x;
        int dist = bfs_q.front().dist;
        bfs_q.pop();
        
        if(pass_map[y][x]){
            pq.push({y, x, dist});
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(check(ny, nx) && !pass[ny][nx] && dist+1 <= i_fuel){
                pass[ny][nx] = 1;
                bfs_q.push({ny, nx, dist+1});
            }
        }
    }
    
    if(pq.empty())
        return {-1, -1, -1};
    return pq.top();
}

DATA find_goal(int pass_num){
    vector<vector<int>> pass;
    pass.resize(n+1);
    for(int i = 0; i <= n; i++)
        pass[i].resize(n+1);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           pass[i][j] = 0;
        }
    }
    
    queue<DATA> bfs_q;
    bfs_q.push({start_y, start_x, 0});
    pass[start_y][start_x] = 1;
    
    while(!bfs_q.empty()){
        DATA cur = bfs_q.front();
        bfs_q.pop();
        
        if(cur.y == end_pos[pass_num-1].first && cur.x == end_pos[pass_num-1].second)
        {
            return cur;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            
            if(check(ny, nx) && !pass[ny][nx] && cur.dist+1 <= i_fuel){
                pass[ny][nx] = 1;
                bfs_q.push({ny, nx, cur.dist+1});
            }
        }
    }
    
    return {-1, -1, -1};
}

void solve(){
    int passenger_num = m;
    
    while(passenger_num){
        DATA passenger = find_passenger();
        if(passenger.dist == -1){
            cout << -1;
            return;
        }
        
        i_fuel -= passenger.dist;
        start_y = passenger.y;
        start_x = passenger.x;
        int pass_num = pass_map[start_y][start_x];
        pass_map[start_y][start_x] = 0;
        
        DATA goal = find_goal(pass_num);
        if(goal.dist == -1){
            cout << -1;
            return;
        }
        i_fuel += goal.dist;
        start_y = goal.y;
        start_x = goal.x;
        passenger_num--;
    }
    
    cout << i_fuel;
    
}

int main() {
    init();
    solve();
    return 0;
}