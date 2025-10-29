#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> visited, oils;
vector<int> oil_amount;
int n, m, oil_num;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int col, int row, const vector<vector<int>> &land){
    queue<pair<int, int>> q;
    q.push({col, row});
    visited[col][row] = 1;
    oils[col][row] = oil_num;
    
    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(!visited[ny][nx] && land[ny][nx] == 1){
                    visited[ny][nx] = 1;
                    oils[ny][nx] = oil_num;
                    cnt++;
                    q.push({ny, nx});
                }
            }
        }
    }
    oil_amount.push_back(cnt);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();   
    m = land[0].size();
    visited.resize(n, vector<int>(m, 0));
    oils.resize(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && land[i][j] == 1){
                bfs(i, j, land);
                oil_num++;
            }
        }
    } 

    for(int i = 0; i < m; i++){ 
        int current_col_oil = 0;
        
        vector<bool> counted(oil_num, false); 
        
        for(int j = 0; j < n; j++){ 
            int oil_id = oils[j][i];
            
            if(oil_id != -1){ 
                if(!counted[oil_id]){ 
                    current_col_oil += oil_amount[oil_id];
                    counted[oil_id] = true; 
                }
            }
        }
        
        answer = max(answer, current_col_oil);
    }
    return answer;
}