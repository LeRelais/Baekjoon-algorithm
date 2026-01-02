#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int n, m;

bool in_range(int y, int x, const vector<vector<int>> &visited, const vector<string> &maps){
    if(y < 0 || x < 0 || y >= n || x >= m) return false;
    if(visited[y][x] == 1) return false; // 이미 방문했으면 false
    if(maps[y][x] == 'X') return false;  // 바다면 false
    return true;
}

int bfs(int col, int row, vector<vector<int>> &visited, const vector<string> &maps){
    visited[col][row] = 1;
    int res = maps[col][row] - '0';
    
    queue<pair<int, int>> q;
    q.push({col, row});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(in_range(ny, nx, visited, maps)){
                visited[ny][nx] = 1;
                q.push({ny, nx});
                res += (maps[ny][nx] - '0'); 
            }
        }
    }
    return res;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].length();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] != 'X' && visited[i][j] == 0){
                answer.push_back(bfs(i, j, visited, maps));
            }
        }   
    }
    
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}