#include <iostream>
#include <queue>

using namespace std;

int n, m, r, c, d;
int room[50][50];

typedef struct _data{
    int y;
    int x;
    int d;
}DATA;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
        }
    }
    
    queue<DATA> q;
    q.push({r,c,d});
    int cnt = 0;
    
    while(true){
        DATA tmp = q.front();
        q.pop();
        
        int y = tmp.y;
        int x = tmp.x;
        int d = tmp.d;
 
        //현재 칸 청소
        if(room[y][x] == 0){
            cnt++;
            room[y][x] = 2;
        }
        
        //주변 4칸 중 청소되지 않은 빈 칸이 있는지 탐색
        bool canClear = false;
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if(room[ny][nx] == 0){
                canClear = true;
                break;
            }
        }
        
        //없다면 한 칸 후진. 만약 후진 불가라면 종료
        if(!canClear){
            int ny = y - dy[d];
            int nx = x - dx[d];
            
            if(room[ny][nx] == 1){
                break;
            }
            
            q.push({ny, nx, d});
        }
        
        //있다면 반시계방향 회전. 회전 이후 앞 칸이 청소되지 않은 빈칸이면 전진. 아니라면 기존 위치를 큐에 삽입
        if(canClear){
            int nd = (d + 3) % 4;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            
            if(room[ny][nx] == 0){
                q.push({ny, nx, nd});
            }
            else{
                q.push({y, x, nd});
            }
        }
    }
    cout << cnt;
    return 0;
}