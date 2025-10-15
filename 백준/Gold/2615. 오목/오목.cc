#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;

int dy[] = {0, 1, 1, 1};
int dx[] = {1, 1, 0, -1};
bool is_finished;
int player_num, y, x;

void init(){
    v.resize(19, vector<int>(19, 0));
    
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            cin >> v[i][j];
        }
    }
}

bool dfs(int player, int d, int cnt, int col, int row){
    int ny = col + dy[d];
    int nx = row + dx[d];
        
    if(cnt == 5){
        if(ny >= 0 && ny < 19 && nx >= 0 && nx < 19){
            if(player == v[ny][nx]){
                return false;
            }
        }
        is_finished = true;
        player_num = player;
        y = col;
        x = row;
        if(d != 3){
            y -= dy[d] * 4;
            x -= dx[d] * 4;
        }
        return true;
    }
    
    
    if(ny >= 0 && ny < 19 && nx >= 0 && nx < 19){
        if(player == v[ny][nx]){
            dfs(player, d, cnt+1, ny, nx);
        }
    }
    return false;
}

void solve(){
    for(int i = 0; i < 19; i++){
        if(is_finished)
            break;
        
        for(int j = 0; j < 19; j++){
            if(v[i][j] != 0){
                if(is_finished)
                    break;
                for(int d = 0; d < 4; d++){
                    int py = i - dy[d];
                    int px = j - dx[d];
                    if(py >= 0 && py < 19 && px >= 0 && px < 19 && v[i][j] == v[py][px])
                        continue;
                    bool is_won = dfs(v[i][j], d, 1, i, j);
                    if(is_won){
                        break;
                    }
                }
            }
        }
    }
    if(is_finished){
        cout << player_num << '\n' << y+1 << ' ' << x+1;
        
    }
    else
        cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}