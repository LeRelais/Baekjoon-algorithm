#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, R, C, K;
string result = "impossible";
bool found = false;

// 1. 사전순으로 빠른 이동 순서 정의: d -> l -> r -> u
//   d: +1, 0
//   l: 0, -1
//   r: 0, +1
//   u: -1, 0
int dy[] = {1, 0, 0, -1}; // y축 (행): 아래, 좌, 우, 위
int dx[] = {0, -1, 1, 0}; // x축 (열): 아래, 좌, 우, 위
char moves[] = {'d', 'l', 'r', 'u'}; 

// DFS 함수: x, y는 현재 행과 열, steps는 현재까지 이동 횟수, path는 현재 경로 문자열
void dfs(int x, int y, int steps, string path) {
    if (found) return; // 이미 가장 빠른 경로를 찾았다면 종료

    // 1. 가지치기 (핵심: K번 이동 및 목표 도달 가능성 검증)
    int remaining_steps = K - steps; // 남은 이동 횟수
    
    // 현재 (x, y)에서 목표 (R, C)까지의 맨해튼 거리 (최소 이동 횟수)
    int manhattan_dist = abs(x - R) + abs(y - C); 

    // A. 남은 이동 횟수가 최소 필요 횟수보다 적으면 불가능
    if (remaining_steps < manhattan_dist) {
        return;
    }

    // B. (남은 이동 횟수 - 최소 이동 횟수)의 홀짝성이 짝수가 아니면 불가능 (패리티 체크)
    // K번 이동해야 하므로, 반드시 manhattan_dist와의 차이만큼 짝수번 왕복해야 한다.
    if ((remaining_steps - manhattan_dist) % 2 != 0) {
        return;
    }
    
    // 2. 종료 조건 (정확히 K번 이동)
    if (steps == K) {
        if (x == R && y == C) {
            result = path;
            found = true; // 그리디 탐색이므로, 첫 발견이 최소 경로
        }
        return;
    }

    // 3. 그리디 탐색 (d, l, r, u 순)
    for (int i = 0; i < 4; ++i) {
        int nx = x + dy[i]; // x는 행 (y), y는 열 (x)로 사용
        int ny = y + dx[i];

        // 격자 범위 체크 (1 <= x <= N, 1 <= y <= M)
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
            // 가지치기를 통과한 경우에만 재귀 호출
            // **주의: 재귀 호출 전에도 가지치기 조건을 한 번 더 점검하면 성능 향상**
            
            // 재귀 호출
            dfs(nx, ny, steps + 1, path + moves[i]);
            
            if (found) return; // 경로를 찾았으면 바로 종료
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n; M = m; R = r; C = c; K = k;
    
    // 1. 초기 불가능 조건 체크 (DFS 시작 전)
    int initial_manhattan = abs(x - r) + abs(y - c);
    if (initial_manhattan > k || (k - initial_manhattan) % 2 != 0) {
        return "impossible";
    }

    // 2. DFS 시작 (x, y는 시작 행/열)
    // 문제의 x, r은 행 (세로), y, c는 열 (가로)입니다.
    dfs(x, y, 0, "");

    return result;
}