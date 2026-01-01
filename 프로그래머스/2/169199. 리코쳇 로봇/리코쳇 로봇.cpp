#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int sy, sx, ey, ex, n, m;
int dir_y[] = {-1, 1, 0, 0};
int dir_x[] = {0, 0, -1, 1};

bool in_range(int y, int x, const vector<string> &board){
    if(y < 0 || y >= n || x < 0 || x >= m)
        return false;
    if(board[y][x] == 'D')
        return false;
    return true;
}

int solution(vector<string> board) {
    int answer = -1;
    n = board.size();
    m = board[0].size();
    
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'R'){
                sy = i;
                sx = j;
            }
            
            if(board[i][j] == 'G'){
                ey = i;
                ex = j;
            }
        }
    }
    
    visited[sy][sx] = 1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {sy,sx}});
    
    while(!pq.empty()){
        int cnt = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(y == ey && x == ex){
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y;
            int nx = x;
            int dy = dir_y[i];
            int dx = dir_x[i];
            
            while(in_range(ny+dy, nx + dx, board)){
                ny += dy;
                nx += dx;
            }
            
            if(!visited[ny][nx]){
                visited[ny][nx] = 1;
                pq.push({cnt+1, {ny, nx}});
            }
        }
    }
    
    return answer;
}