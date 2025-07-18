#include <iostream>
#include <vector> 
#include <numeric>

using namespace std;

// 학생 수 N (1 <= N <= 10,000)
// 친구관계 수 M (0 <= M <= 10,000)
// 가지고 있는 돈 k (1 <= k <= 10,000,000)
// 친구비 Ai (1 <= Ai <= 10,000)

int n, m, k;
int friend_cost[10001]; // 각 학생의 초기 친구비, 합쳐진 집합의 최소 친구비 저장용
int parent[10001];      // Union-Find parent 배열
bool visited_root[10001]; // 각 연결 요소의 대표 노드를 방문했는지 (비용을 합산했는지) 체크

// Union-Find: Find 연산 (경로 압축 최적화)
int find_parent(int i) {
    if (i == parent[i]) 
        return i;
    return parent[i] = find_parent(parent[i]);
}

// Union-Find: Union 연산
// 두 집합을 합치고, 합쳐진 집합의 대표 노드에 해당 집합의 최소 친구비를 기록
void make_friend(int a, int b) {
    int root_a = find_parent(a);
    int root_b = find_parent(b);
    
    if (root_a == root_b) { // 이미 같은 집합
        return;
    }
    
    // 비용이 더 작은 쪽을 새로운 대표로 만듭니다.
    // 이는 'Union by Cost' 방식과 유사합니다.
    if (friend_cost[root_a] > friend_cost[root_b]) {
        parent[root_a] = root_b; // root_a의 부모를 root_b로 설정
    } else { // friend_cost[root_a] <= friend_cost[root_b]
        parent[root_b] = root_a; // root_b의 부모를 root_a로 설정
    }
    
    if (friend_cost[root_a] < friend_cost[root_b]) {
        parent[root_b] = root_a; // root_b를 root_a 아래로
    } else { // friend_cost[root_a] >= friend_cost[root_b]
        parent[root_a] = root_b; // root_a를 root_b 아래로
    }
}


// init 함수는 입력 받기와 parent 배열 초기화를 겸합니다.
void init_data_and_union_find() { // 함수명 변경하여 역할 명확화
    for (int i = 1; i <= n; i++) {
        cin >> friend_cost[i]; // 각 학생의 초기 친구비 입력
        parent[i] = i;         // Union-Find parent 배열 초기화
        visited_root[i] = false; // 방문 여부 초기화
    }
}

void solve() {
    int u, v; // 친구 관계를 입력받을 변수
    
    // 친구 관계를 처리하여 연결 요소들을 형성
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        
        // make_friend 함수 로직을 여기에 통합하여 friend_cost 업데이트를 정확히 수행
        int root_u = find_parent(u);
        int root_v = find_parent(v);

        if (root_u != root_v) { // 두 집합의 대표가 다르면 합친다
            // 더 작은 친구비를 가진 쪽을 새로운 대표로 삼고, 다른 쪽을 그 아래로 붙인다.
            if (friend_cost[root_u] < friend_cost[root_v]) {
                parent[root_v] = root_u; 
            } else { // friend_cost[root_u] >= friend_cost[root_v]
                parent[root_u] = root_v;
            }
        }
        // 만약 root_u == root_v 이면 이미 같은 집합이므로 아무것도 할 필요 없음.
        // 사이클 생성을 막는 것이 아니라, 이미 친구 관계이므로 그냥 병합만 진행
    }
    
    long long total_min_cost = 0; // 최소 총 비용 (k가 1천만까지 가능하므로 long long 필요)
    
    // 모든 학생을 순회하며, 각 연결 요소의 최종 대표 노드를 찾아 비용 합산
    for (int i = 1; i <= n; i++) {
        int root = find_parent(i); // i가 속한 집합의 최종 대표 찾기
        
        // 해당 대표 노드가 아직 비용 합산에 사용되지 않았다면
        if (!visited_root[root]) {
            total_min_cost += friend_cost[root]; // 대표 노드의 (해당 집합의) 최소 친구비 더하기
            visited_root[root] = true; // 이 대표 노드는 비용을 사용했음을 표시
        }
    }
    
    if (total_min_cost <= k) {
        cout << total_min_cost << '\n';
    } else {
        cout << "Oh no\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> k; // n, m, k 입력
    
    init_data_and_union_find(); // 데이터 초기화 및 parent 배열 설정
    solve(); // 문제 해결
    
    return 0;
}