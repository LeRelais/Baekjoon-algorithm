#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int sy, sx, ey, ex, ly, lx, n, m;

bool in_range(int y, int x, vector<vector<int>> visited, const vector<string> &maps){
    if(y < 0 || x < 0 || y >= n || x >= m)
        return false;
    if(visited[y][x] != -1)
        return false;
    if(maps[y][x] == 'X')
        return false;
    return true;
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<string> maps) {
    int answer = 0;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(maps[i][j] == 'S'){
                sy = i;
                sx = j;
            }
            else if(maps[i][j] == 'L'){
                ly = i;
                lx = j;
            }
            else if(maps[i][j] == 'E'){
                ey = i;
                ex = j;
            }
        }
    }
    
    n = maps.size();
    m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    // 1. start -> 레버
    queue<pair<int, int>> to_lever;
    bool reached_lever = false;
    to_lever.push({sy, sx});
    visited[sy][sx] = 0;
    
    while(!to_lever.empty()){
        int y = to_lever.front().first;
        int x = to_lever.front().second;
        to_lever.pop();
        
        if(y == ly && x == lx){
            reached_lever = true;
            answer += visited[y][x];
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(in_range(ny, nx, visited, maps)){
                visited[ny][nx] = visited[y][x] + 1;
                to_lever.push({ny, nx});
            }
        }
    }

    if(!reached_lever){
        answer = -1;
        return answer;
    }
    
    // 2. 레버 -> end
    visited = vector<vector<int>>(n, vector<int>(m, -1));
    queue<pair<int, int>> to_exit;
    bool reached_exit = false;
    to_exit.push({ly, lx});
    visited[ly][lx] = 0;
    
    while(!to_exit.empty()){
        int y = to_exit.front().first;
        int x = to_exit.front().second;
        to_exit.pop();
        
        if(y == ey && x == ex){
            reached_exit = true;
            answer += visited[y][x];
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(in_range(ny, nx, visited, maps)){
                visited[ny][nx] = visited[y][x] + 1;
                to_exit.push({ny, nx});
            }
        }
    }
    
    if(!reached_exit){
        answer = -1;
        return answer;
    }
    
    return answer;
}