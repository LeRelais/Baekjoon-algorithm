#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int r, c, n, turn, throw_height;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<vector<char>> cave;
vector<vector<int>> visited;

void init(){
    cin >> r >> c;
    string str;
    cave.resize(r, vector<char>(c));
    for(int i = 0; i < r; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            cave[i][j] = str[j];
        }
    }
    cin >> n;
}

void throw_stick(){
   int cur_y = r - throw_height;
    
    if (turn % 2 == 0) { // 홀수 턴: 왼쪽에서 오른쪽으로
        for (int x = 0; x < c; x++) {
            if (cave[cur_y][x] == 'x') {
                cave[cur_y][x] = '.';
                break;
            }
        }
    } else { // 짝수 턴: 오른쪽에서 왼쪽으로
        for (int x = c - 1; x >= 0; x--) {
            if (cave[cur_y][x] == 'x') {
                cave[cur_y][x] = '.';
                break;
            }
        }
    }
}

bool check(int y, int x){
    if(y < 0 || y >= r || x < 0 || x >= c)
        return false;
    if(visited[y][x])
        return false;
    if(cave[y][x] == '.')
        return false;
    return true;
}

vector<pair<int, int>> find_cluster(int r, int c){
    vector<pair<int, int>> cluster;
    queue<pair<int, int>> q;
    
    q.push({r, c});
    visited[r][c] = 1;
    cluster.push_back({r, c});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(check(ny, nx)){
                q.push({ny, nx});
                visited[ny][nx] = 1;
                cluster.push_back({ny, nx});
            }
        }
    }
    
    return cluster;
}

void drop_cluster(vector<pair<int, int>> &cluster){
    int drop_dist = 1;
    while(1){
        bool can_drop = true;
        for(const auto &mineral : cluster){
            int ny = mineral.first + drop_dist;
            int nx = mineral.second;
            
            // 바닥에 닿거나
            if (ny >= r) {
                can_drop = false;
                break;
            }
            
            // 다른 미네랄에 닿는지 확인 (현재 떨어뜨리는 클러스터에 속하지 않는 미네랄)
            if (cave[ny][nx] == 'x') {
                // 이 미네랄이 현재 클러스터에 속하는지 확인
                bool belongs_to_current_cluster = false;
                for(const auto& m : cluster){
                    if(m.first == ny && m.second == nx){
                        belongs_to_current_cluster = true;
                        break;
                    }
                }
                if(!belongs_to_current_cluster){
                    can_drop = false;
                    break;
                }
            }
        }
        if(!can_drop)
            break;
        
        drop_dist++;
    }
    
     drop_dist--; // 멈춰야 할 위치 바로 위까지 이동

    // 기존 클러스터 위치를 비우기
    for(const auto& mineral : cluster) {
        cave[mineral.first][mineral.second] = '.';
    }
    
    // 새로운 위치로 이동
    for(const auto& mineral : cluster) {
        cave[mineral.first + drop_dist][mineral.second] = 'x';
    }
}

void move_cluster(){
   visited.assign(r, vector<int>(c, 0));
    
    queue<pair<int, int>> q;
    for(int j = 0; j < c; j++){
        if(cave[r-1][j] == 'x'){
            q.push({r-1, j});
            visited[r-1][j] = 1;
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(check(ny, nx)){
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    
    //공중에 뜬 cluster 이동
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!visited[i][j] && cave[i][j] == 'x'){
                vector<pair<int, int>> cluster = find_cluster(i, j);
                drop_cluster(cluster);
                return;
            }
        }
    }
}

void print(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << cave[i][j];
        }
        cout << endl;
    }
}

void solve(){
    for(int t = 0; t < n; t++){
        cin >> throw_height;
        throw_stick();
        move_cluster();
        turn++;
    }
    print();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
}