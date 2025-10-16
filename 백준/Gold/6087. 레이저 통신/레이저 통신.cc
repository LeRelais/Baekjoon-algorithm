#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _data{
    int y;
    int x;
    int d;
    int cnt;
} DATA;

struct cmp{
  bool operator()(const DATA &a, const DATA &b){
      return a.cnt > b.cnt;
  }  
};

vector<string> board;
vector<vector<vector<int>>> dist;
int w, h, start_y, start_x, end_y, end_x;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init(){
    cin >> w >> h;
    string str;
    int flag = 1;
    for(int i = 0; i < h; i++){
        cin >> str;
        board.push_back(str);
        for(int j = 0; j < board[i].length(); j++){
            if(board[i][j] == 'C'){
                if(flag){
                    start_y = i;
                    start_x = j;
                    flag = 0;
                }
                else{
                    end_y = i;
                    end_x = j;
                }
            }
        }
    }
    
    dist.resize(h, vector<vector<int>>(w, vector<int>(4, 987654321)));
}

void solve(){
    priority_queue<DATA, vector<DATA>, cmp> q;
    q.push({start_y, start_x, -1, 0});
    
    for(int i = 0; i < 4; i++){
        dist[start_y][start_x][i] = 0;
    }
    
    int res = 987654321;
    while(!q.empty()){
        int y = q.top().y;
        int x = q.top().x;
        int d = q.top().d;
        int cnt = q.top().cnt;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nd = i;
            int ncnt = cnt;
            
            if(ny < 0 || nx < 0 || ny >= h || nx >= w || board[ny][nx] == '*')
                continue;
            
            if(nd != d && d != -1)
                ncnt++;
            
            if(dist[ny][nx][nd] > ncnt){
                dist[ny][nx][nd] = ncnt;
                q.push({ny, nx, nd, ncnt});
            }
        }
    }
    
    for(int i = 0; i < 4; i++){
        res = min(res, dist[end_y][end_x][i]);
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}