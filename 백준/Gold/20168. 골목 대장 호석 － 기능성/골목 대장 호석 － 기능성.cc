#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

// 최대 요금은 1000까지 가능
const int MAX_FEE = 1001; 
const int INF = 987654321; 

int N, M, A, B, C; 
// graph: {도착 교차로, 요금}
vector<vector<pair<int, int>>> graph;

// dist[i][j]: i번 교차로에 도착했을 때, 경로 상 최대 요금이 j일 때의 최소 총 비용
int dist[11][MAX_FEE]; 

// 우선순위 큐에 들어갈 데이터 구조
struct State {
    int san;  // 현재까지의 최대 요금 (Max Fee)
    int cost; // 현재까지의 총 비용 (Total Cost)
    int x;    // 현재 교차로 번호

    // 우선순위: cost가 작은 순 -> san이 작은 순
    bool operator>(const State& other) const {
        if (cost != other.cost) {
            return cost > other.cost;
        }
        return san > other.san;
    }
};

void solve() {
    // 1. 입력 받기 및 그래프 구성
    if (!(cin >> N >> M >> A >> B >> C)) return;
    
    graph.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int from, to, value;
        if (!(cin >> from >> to >> value)) return;
        
        graph[from].push_back({to, value});
        graph[to].push_back({from, value});
    }

    // 2. dist 배열 초기화
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < MAX_FEE; ++j) {
            dist[i][j] = INF;
        }
    }

    // 3. 다익스트라 시작
    // {cost, san, x} 순으로 정렬하는 priority_queue (State 구조체의 > 연산자 사용)
    priority_queue<State, vector<State>, greater<State>> pq;
    
    // 시작점 설정: A번 교차로, 총 비용 0, 최대 요금 0
    dist[A][0] = 0;
    pq.push({0, 0, A});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int san = current.san;
        int cost = current.cost;
        int u = current.x;

        // 힙에서 꺼낸 값이 이미 저장된 값보다 크다면 무시 (최적화)
        if (cost > dist[u][san]) continue;
        
        // 4. 인접 노드 탐색
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int edge_fee = edge.second;

            // 새로운 최대 요금: 현재 최대 요금과 골목 요금 중 큰 값
            int n_san = max(san, edge_fee);
            // 새로운 총 비용
            int n_cost = cost + edge_fee;

            // 총 비용 C 제한 검사
            if (n_cost > C) continue;
            
            // 다익스트라 갱신 조건: 
            // 새로운 최대 요금(n_san) 상태로 v에 도착하는 최소 비용이 갱신되는 경우
            if (dist[v][n_san] > n_cost) {
                dist[v][n_san] = n_cost;
                pq.push({n_san, n_cost, v});

                // **중요**: 현재 n_san보다 더 큰 san 값들(n_san+1, n_san+2, ...)에 대해서도
                // 이 최소 비용 n_cost를 전파하여 갱신합니다. 
                // (어차피 최대 요금이 n_san보다 크다면 n_cost가 최소 총 비용이 됩니다.)
                for (int next_san = n_san + 1; next_san < MAX_FEE; ++next_san) {
                    if (dist[v][next_san] > n_cost) {
                        dist[v][next_san] = n_cost;
                    } else {
                        // 비용이 더 이상 줄어들지 않으면 루프 중단 (최적화)
                        break; 
                    }
                }
            }
        }
    }

    // 5. 최종 결과 계산
    int min_max_fee = -1;
    
    // B에 대해 모든 최대 요금 상태(j=0 to 1000)를 검사
    for (int j = 0; j < MAX_FEE; ++j) {
        // 총 비용이 C 이하인 경로가 존재하고,
        if (dist[B][j] <= C) {
            // 그 때의 최대 요금 j가 답이 됩니다.
            min_max_fee = j;
            break; // j가 작은 순서대로 검사했으므로, 처음 발견된 j가 최소 최대 요금입니다.
        }
    }

    cout << min_max_fee << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}