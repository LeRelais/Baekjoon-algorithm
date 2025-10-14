#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int r, c, n, flag = 0;
vector<string> cave;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init(){
    cin >> r >> c;
    string tmp;
    for(int i = 0; i < r; i++){
       cin >> tmp;
       cave.push_back(tmp);
    }
    cin >> n;
}

void throw_stick(int height){
    int adjusted_height = r - height;
    if(!flag){
        for(int i = 0; i < c; i++){
            if(cave[adjusted_height][i] == 'x'){
                cave[adjusted_height][i] = '.';
                break;
            }
            
        }
    }
    else{
        for(int i = c-1; i >= 0; i--){
            if(cave[adjusted_height][i] == 'x'){
                cave[adjusted_height][i] = '.';
                break;    
            }
        }   
    }
}

void bfs(int col, int row, vector<vector<int>> &cluster){
    queue<pair<int, int>> q;
    q.push({col, row});
    cluster[col][row] = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                if(!cluster[ny][nx] && cave[ny][nx] == 'x'){
                    q.push({ny, nx});
                    cluster[ny][nx] = 1;
                }
            }
        }
    }
}

void check_cluster(vector<vector<int>> &cluster){
    for(int i = 0; i < c; i++){
        if(cave[r-1][i] == 'x' && !cluster[r-1][i]){
            bfs(r-1, i, cluster);
        }
    }
}

void move_cluster(vector<vector<int>> cluster){
    vector<pair<int, int>> tmp;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!cluster[i][j] && cave[i][j] == 'x'){
                tmp.push_back({i, j});
            }
        }
    }
    
    if(tmp.empty())
        return;
        
    int cnt = 0, break_flag = 1;
    
    while(1){
        for(int i = 0; i < tmp.size(); i++){
            int y = tmp[i].first;
            int x = tmp[i].second;
            
            if(y + cnt + 1 >= r){
                break_flag = 0;
                break;
            }
            
            if(cave[y+cnt+1][x] == 'x' && cluster[y+cnt+1][x]){
                break_flag = 0;
                break;
            }
        }
    
        
        if(!break_flag)
            break;
        
        cnt++;
    }
    for(int i = tmp.size()-1; i >= 0; i--){
        int y = tmp[i].first;
        int x = tmp[i].second;

        cave[y][x] = '.';
        cave[y+cnt][x] = 'x';
    }
}

void solve(){
    int height;
    for(int i = 0; i < n; i++){
        cin >> height;
        throw_stick(height);
        vector<vector<int>> cluster = vector<vector<int>>(r, vector<int>(c, 0));
        check_cluster(cluster);
        move_cluster(cluster);
        flag = !flag;
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << cave[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    init();
    solve();
}