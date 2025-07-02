#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

// Union-Find를 위한 parent 배열
// 문제의 최대 m(정점 수)이 200000이므로 200001 크기로 선언 (1-based indexing)
int parent[200001];

// 간선 정보를 저장할 구조체 (가독성 향상)
struct Edge {
    int u, v, weight;
};

// 간선을 가중치 기준으로 오름차순 정렬하기 위한 비교 함수
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find: Find 연산 (경로 압축 최적화)
int find_parent(int i) {
    if (i == parent[i]) // 자기 자신이 부모라면 루트
        return i;
    // 경로 압축: 현재 노드의 부모를 루트로 직접 연결
    return parent[i] = find_parent(parent[i]); 
}

// Union-Find: Union 연산 (두 집합을 합침)
// true: 성공적으로 합쳐짐 (사이클 아님), false: 이미 같은 집합이었음 (사이클)
bool union_sets(int a, int b) {
    a = find_parent(a); // a의 대표 찾기
    b = find_parent(b); // b의 대표 찾기
    
    if (a != b) { // 대표가 다르면 서로 다른 집합이므로 합친다
        parent[b] = a; // b의 대표를 a의 대표 아래로 연결
        return true;   // 합치기 성공
    }
    return false;  // 이미 같은 집합이었음 (사이클 발생)
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m_nodes, n_edges; // m: 집의 수 (정점), n: 길의 수 (간선)

    while (cin >> m_nodes >> n_edges) {
        if (m_nodes == 0 && n_edges == 0) {
            break; // 0 0 입력 시 종료
        }

        vector<Edge> edges; // 간선들을 저장할 벡터
        long long total_cost_all_roads = 0; // 모든 길의 총 비용 (long long으로 충분히 큰 값 커버)

        for (int i = 0; i < n_edges; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            total_cost_all_roads += w; // 모든 길의 비용을 미리 합산
        }

        // 1. 간선들을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), compareEdges);

        // 2. Union-Find parent 배열 초기화
        // 각 정점이 자기 자신을 부모로 가리키도록 설정
        // 정점 번호가 0부터 시작할 수도 있고, 1부터 시작할 수도 있음.
        // 문제에서 x, y가 집 번호이고 최대 200000이므로, 1부터 m_nodes까지 사용한다고 가정
        for (int i = 0; i < m_nodes; ++i) { // 정점 0부터 m_nodes-1까지라면 이대로
             parent[i] = i;
        }
        // 만약 정점 번호가 1부터 m_nodes까지라면 아래처럼
        // for (int i = 1; i <= m_nodes; ++i) {
        //      parent[i] = i;
        // }


        long long mst_cost = 0; // MST의 총 가중치
        int edges_in_mst_count = 0; // MST에 포함된 간선의 개수

        // 3. 정렬된 간선들을 순회하며 MST 구성
        for (const auto& edge : edges) {
            // MST에 (정점 수 - 1)개의 간선이 모두 포함되면 종료
            if (edges_in_mst_count == m_nodes - 1) { 
                break;
            }

            // 간선의 양 끝 정점
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            // u와 v가 서로 다른 집합에 속해 있다면 (사이클이 형성되지 않는다면)
            if (union_sets(u, v)) { 
                mst_cost += weight; // MST에 간선 추가
                edges_in_mst_count++; // 간선 개수 증가
            }
        }
        
        // 절약할 수 있는 최대 비용 = 모든 길의 총 비용 - MST의 총 비용
        cout << total_cost_all_roads - mst_cost << "\n";
    }

    return 0;
}