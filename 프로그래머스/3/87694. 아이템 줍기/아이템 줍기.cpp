#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int board[101][101], border[101][101], visited[101][101];
int max_y, max_x;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

//
bool checkCondition(int y, int x){
    if (y <= 0 || x <= 0 || y > 100 || x > 100)
        return false;
    if(visited[y][x])
        return false;
    if(!board[y][x])
        return false;
    return true;
}

void init(vector<vector<int>> rectangle){
    
    //직사각형 배치
    for(int x = 0; x < rectangle.size(); x++){
        for(int y = 0; y < rectangle[x].size(); y++){
            rectangle[x][y] *= 2;
        }
        int x1 = rectangle[x][0];
        int x2 = rectangle[x][2];
        int y1 = rectangle[x][1];
        int y2 = rectangle[x][3];
        
        for(int i = y1; i <= y2; i++){
            for(int j = x1; j <= x2; j++){
                board[i][j] = 1;
            }
        }
    }
        
    //직사각형들의 바깥쪽 테두리 구하기'
    for(int x = 0; x < rectangle.size(); x++){
        int x1 = rectangle[x][0];
        int x2 = rectangle[x][2];
        int y1 = rectangle[x][1];
        int y2 = rectangle[x][3];
        
        for(int i = y1+1; i < y2; i++){
            for(int j = x1+1; j < x2; j++){
                board[i][j] = 0;
            }
        }
    }
}

int solve(int characterX, int characterY, int itemX, int itemY){
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    queue<pair<int, int>> q;
    q.push({characterY, characterX});
    visited[characterY][characterX] = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == itemY && x == itemX){
            return visited[y][x] / 2;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(checkCondition(ny, nx)){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    init(rectangle);
    answer = solve(characterX, characterY, itemX, itemY);
    return answer;
}