#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

// 전역 변수: 테스트 케이스마다 초기화 필요
// 배열 크기를 101로 설정하여 1-based (1~100) 좌표를 바로 사용
vector<pair<int, int>> route[101]; // route[로봇ID] -> 경로 벡터
int dy[] = {-1, 1, 0, 0}; // 상, 하 (r 변동)
int dx[] = {0, 0, -1, 1}; // 좌, 우 (c 변동)
int R_MAX = 100, C_MAX = 100; // 최대 좌표

// BFS: start 포인트에서 end 포인트까지의 최단 경로를 찾아 route[num]에 저장
// 1-based 좌표를 사용하도록 수정
void bfs(int num, int start_idx, int end_idx, const vector<vector<int>> &points){
    // 포인트 번호는 1-based, points 인덱스는 0-based
    int start_y = points[start_idx][0];
    int start_x = points[start_idx][1];
    int end_y = points[end_idx][0];
    int end_x = points[end_idx][1];
    
    // 1-based 좌표에 맞게 크기 101x101 (인덱스 1~100 사용)
    bool visited[101][101] = {false};
    pair<int, int> prev[101][101]; 
    
    // prev 배열 초기화 (여기서는 1~100만 사용)
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            prev[i][j] = {-1, -1};
        }
    }
    
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == end_y && x == end_x) break;
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 1-based 범위 체크 (1 <= y, x <= 100)
            if(ny >= 1 && ny <= R_MAX && nx >= 1 && nx <= C_MAX){
                if(!visited[ny][nx]){
                    visited[ny][nx] = true;
                    prev[ny][nx] = {y, x};
                    q.push({ny, nx});
                }
            }
        }
    }
    
    // 경로 역추적 및 route[num]에 저장
    vector<pair<int, int>> tmp;
    int curr_y = end_y;
    int curr_x = end_x;
    
    while(curr_y != -1 || curr_x != -1){
        tmp.push_back({curr_y, curr_x});
        
        if(curr_y == start_y && curr_x == start_x) break; // 시작점에 도달하면 멈춤
        
        pair<int, int> p = prev[curr_y][curr_x];
        curr_y = p.first;
        curr_x = p.second;
    }
    
    // 경로를 역순으로 저장했으므로 뒤집기
    reverse(tmp.begin(), tmp.end());
    
    // 시작점을 제외하고 경로를 저장 (시작점은 이전 구간의 끝점이므로)
    // 하지만, 이 문제에서는 로봇의 '순간 위치'를 비교하므로 시작점도 필요합니다.
    // route[num]에 현재 저장된 경로(이전 구간의 끝점)가 있다면 이어붙여야 합니다.
    
    // tmp에는 [start, ..., end] 경로가 저장되어 있습니다.
    // 기존 경로의 끝점과 현재 경로의 시작점이 겹치므로, 중복을 제거하고 이어 붙입니다.
    
    // tmp의 첫 번째 요소(start)는 이미 route[num]에 있다면 제거해야 합니다.
    size_t start_index = route[num].empty() ? 0 : 1; 
    
    for(size_t i = start_index; i < tmp.size(); i++){
        route[num].push_back(tmp[i]);
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    // ⭐️ 1. 전역 변수 초기화 (테스트 케이스 대응)
    for (int i = 0; i < 101; ++i) {
        route[i].clear();
    }
    
    // 2. 경로 계산 (routes를 순회하며 BFS 호출)
    int num_robots = routes.size();
    int max_time = 0; // 최장 경로의 길이 (시뮬레이션 시간)

    for(int i = 0; i < num_robots; i++){
        // 로봇 i의 경로는 routes[i]
        for(size_t j = 0; j < routes[i].size() - 1; j++){
            int start_point_idx = routes[i][j] - 1;
            int end_point_idx = routes[i][j+1] - 1;
            
            // 로봇 번호 i, start, end 포인트 인덱스(0-based) 전달
            bfs(i, start_point_idx, end_point_idx, points);
        }
        max_time = max(max_time, (int)route[i].size());
    }
    
    // 3. 충돌 시뮬레이션
    int total_collision = 0;
    
    // t는 0초부터 시작하여 max_time - 1초까지 (총 max_time개의 위치가 존재)
    for (int t = 0; t < max_time; ++t) {
        // 시간 t에서의 (y, x) 좌표별 로봇 수를 저장
        map<pair<int, int>, int> current_positions;
        
        for (int robot_idx = 0; robot_idx < num_robots; ++robot_idx) {
            // 로봇이 아직 운송 중인지 확인 (경로 길이보다 t가 작아야 함)
            if (t < route[robot_idx].size()) { 
                pair<int, int> pos = route[robot_idx][t];
                current_positions[pos]++;
            }
            // 운송을 마친 로봇은 이 루프에서 제외됨
        }
        
        // 4. 충돌 카운트
        for (const auto& entry : current_positions) {
            // 한 좌표에 로봇이 2대 이상 모인 경우
            if (entry.second >= 2) {
                total_collision++;
            }
        }
    }
    
    return total_collision;
}