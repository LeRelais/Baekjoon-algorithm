#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 1. 전역 변수 설정 (편의상)
char boxes[52][52];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// 2. 접근 가능한 모든 target_char의 좌표를 찾고, 해당 상자를 제거합니다.
// 리턴 값: 제거된 상자의 개수
int get_accessible_containers(int n, int m, char target_char) {
    bool visited[52][52] = {false};
    queue<pair<int, int>> q;
    int removed_count = 0;

    // 큐 초기화: 모든 외부 경계의 빈 공간을 시작점으로 추가
    // 0-based 인덱스를 사용할 경우: (0, 0) ~ (N+1, M+1)
    
    // 큐에 초기 빈 공간(패딩)을 추가
    for (int i = 0; i <= n + 1; ++i) { // y=0, N+1 행 전체
        if (boxes[i][0] == ' ') { q.push({i, 0}); visited[i][0] = true; }
        if (boxes[i][m + 1] == ' ') { q.push({i, m + 1}); visited[i][m + 1] = true; }
    }
    for (int j = 0; j <= m + 1; ++j) { // x=0, M+1 열 전체 (위에서 추가된 부분 제외)
        if (boxes[0][j] == ' ' && !visited[0][j]) { q.push({0, j}); visited[0][j] = true; }
        if (boxes[n + 1][j] == ' ' && !visited[n + 1][j]) { q.push({n + 1, j}); visited[n + 1][j] = true; }
    }
    
    // 큐에 있는 모든 빈 공간에서 접근 가능한 상자를 찾을 때까지 BFS 진행
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 경계 조건: 0 <= ny <= N+1, 0 <= nx <= M+1
            if (ny >= 0 && ny <= n + 1 && nx >= 0 && nx <= m + 1) {
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;

                    if (boxes[ny][nx] == target_char) {
                        // 1. 요청 물품 발견 (접근 가능) -> 제거 및 카운트
                        boxes[ny][nx] = ' ';
                        removed_count++;
  
                        
                    } else if (boxes[ny][nx] == ' ') {
                        // 3. 빈 공간이면 계속 탐색 (연결된 외부 공간 확장)
                        q.push({ny, nx});
                    }
                    // else: 다른 종류의 상자('B'가 'A'로 가는 길을 막는 경우)는 visited만 true로 두고 큐에 넣지 않음
                }
            }
        }
    }
    return removed_count;
}

// 3. 메인 솔루션 함수
int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].length();
    
    // boxes 초기화 (1-based index 사용을 위해 52x52)
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++)
            boxes[i][j] = ' ';
    }
    
    // storage 내용을 boxes에 복사 (1-based index)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            boxes[i][j] = storage[i-1][j-1];
    }
    
    int total_removed = 0;
    
    for(const string& req : requests){
        char target_char = req[0];
        
        if(req.length() == 1) {
            // 지게차 요청: 접근 가능한 컨테이너만 꺼냄 (BFS 필요)
            total_removed += get_accessible_containers(n, m, target_char);
            
        } else if (req.length() == 2) {
            // 크레인 요청: 모든 컨테이너를 꺼냄 (전체 순회 필요)
            int crane_removed = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(boxes[i][j] == target_char) {
                        boxes[i][j] = ' '; // 제거
                        crane_removed++;
                    }
                }
            }
            total_removed += crane_removed;
        }
    }
    
    // 4. 남은 컨테이너 수 계산
    int final_count = n * m - total_removed;
    return final_count;
}