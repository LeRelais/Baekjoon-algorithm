#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
using namespace std;

int n, q, id;
vector<vector<int>> ice, ice_tmp;
vector<int> cmd;
map<int, int> id_cnt;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

void init(){
    cin >> n >> q;
    int l = pow(2, n);
    ice.resize(l, vector<int>(l, 0));
    ice_tmp.resize(l, vector<int>(l));
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            cin >> ice[i][j];
        }
    }
    cmd.resize(q);
    for(int i = 0; i < q; i++)
        cin >> cmd[i];
}

void rotate_ice(int y, int x, int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            ice_tmp[y + j][x + len - 1 - i] = ice[y+i][x+j];
        }
    }
    
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            ice[y + i][x + j] = ice_tmp[y + i][x + j];
        }
    }
}

void melt_ice(){
    int N_size = ice.size();
    vector<pair<int, int>> to_melt; // 녹일 칸의 좌표 저장
    
    for(int i = 0; i < N_size; i++){
        for(int j = 0; j < N_size; j++){
            if(ice[i][j] == 0) continue; // 얼음이 없으면 스킵

            int near_ice = 0; // 인접한 얼음 칸 수
            for(int d = 0; d < 4; d++){
                int ni = i + dy[d];
                int nj = j + dx[d];

                if(ni >= 0 && ni < N_size && nj >= 0 && nj < N_size){
                    if(ice[ni][nj] > 0){
                        near_ice++;
                    }
                }
            }
            
            // 3개 미만의 얼음에 인접하면 녹을 목록에 추가
            if(near_ice < 3){
                to_melt.push_back({i, j});
            }
        }
    }
    
    // 녹일 칸 목록을 한 번에 반영
    for(const auto& p : to_melt){
        ice[p.first][p.second]--;
    }
}

void bfs(int col, int row, vector<vector<int>> &visited){

    queue<pair<int, int>> qq;
    qq.push({col, row});
    visited[col][row] = id;
    int cnt = 1;

    while(!qq.empty()){
        int y = qq.front().first;
        int x = qq.front().second;
        qq.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < ice.size() && nx >= 0 && nx < ice.size()){

                if(!visited[ny][nx] && ice[ny][nx]){
                    qq.push({ny, nx});
                    visited[ny][nx] = id;
                    cnt++;
                }
            }
        }
    }
    id_cnt[id] = cnt;
    id++;
}

void solve(){
    
    for(int x = 0; x < cmd.size(); x++){
        int l = pow(2, cmd[x]);
        
        for(int i = 0; i < ice.size(); i += l){
            for(int j = 0; j < ice[0].size(); j += l){
                rotate_ice(i, j, l);
            }
        }
        
        melt_ice();
    }
    
    vector<vector<int>> visited = vector<vector<int>>(ice.size(), vector<int>(ice.size(), 0));
    id = 1;
    int total_size = 0;
    for(int i = 0; i < ice.size(); i++){
        for(int j = 0; j < ice.size(); j++){
            if(!visited[i][j] && ice[i][j]){
                bfs(i, j, visited);
            }
            if(ice[i][j])
                total_size += ice[i][j];
        }
    }
    
    int max_cnt = 0;
    for(auto i = id_cnt.begin(); i != id_cnt.end(); i++){
        max_cnt = max(i->second, max_cnt);
    }
    
    cout << total_size << '\n' << max_cnt;
}

int main() {
    
    init();
    solve();
    return 0;
}