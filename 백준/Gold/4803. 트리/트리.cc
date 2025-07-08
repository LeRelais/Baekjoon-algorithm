#include <iostream>
#include <set> // std::set 사용

using namespace std;

// 전역 변수들
int n, m, a, b;
int parent[501];
bool is_cyclic[501]; // 각 집합의 루트 노드에 해당 집합이 사이클을 포함하는지 여부

// Union-Find: Find 연산 (경로 압축)
int find_parent(int i) {
    if (i == parent[i]) 
        return i;
    
    return parent[i] = find_parent(parent[i]);
}

// Union-Find: Union 연산
// 두 집합을 합치고, 합쳐질 때 사이클이 발생했는지 또는 합쳐지는 두 집합 중 하나라도 이미 사이클을 포함하고 있었는지
// 여부를 is_cyclic 배열에 반영
bool union_sets(int a, int b) {
    int root_a = find_parent(a);
    int root_b = find_parent(b);
    
    if (root_a != root_b) { // 두 집합의 대표가 다르면 합친다
        parent[root_b] = root_a;
        // 두 집합 중 하나라도 사이클이 있었다면, 합쳐진 새 집합도 사이클을 가짐
        is_cyclic[root_a] = is_cyclic[root_a] || is_cyclic[root_b];
        return true; // 합치기 성공 (지금 간선으로 사이클이 발생하진 않음)
    } else { // 대표가 같으면 이미 같은 집합이었으므로 사이클 발생!
        is_cyclic[root_a] = true; // 해당 집합에 사이클이 발생했음을 표시
        return false; // 사이클 발생
    }
}

// parent 및 is_cyclic 배열 초기화 함수
void init_union_find(int num_nodes) {
    for (int i = 1; i <= num_nodes; i++) {
        parent[i] = i;
        is_cyclic[i] = false; // 초기에는 어떤 집합도 사이클을 포함하지 않음
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; // 테스트 케이스 번호
    
    while (true) {
        cin >> n >> m;
        
        if (n == 0 && m == 0) {
            break;
        }
        
        init_union_find(n); // parent와 is_cyclic 배열 초기화
        
        // 모든 간선을 처리 (사이클 여부는 union_sets에서 처리됨)
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            union_sets(a, b); // union_sets에서 is_cyclic 상태 업데이트
        }
        
        // 트리의 개수를 세는 로직
        set<int> tree_roots; // 트리가 되는 연결 요소의 루트들을 저장할 set

        // 모든 정점을 순회하며 유니크한 루트를 찾고, 해당 루트가 사이클이 없는지 확인
        for (int i = 1; i <= n; i++) {
            int root = find_parent(i); // 현재 정점의 최종 루트를 찾음
            // 해당 루트가 사이클을 포함하지 않는다면, 트리의 후보가 됨
            if (!is_cyclic[root]) {
                tree_roots.insert(root); // 유니크한 루트를 set에 추가
            }
        }
        
        // 이제 트리의 개수는 tree_roots.size()가 됩니다.
        int num_trees = tree_roots.size();
        
        cout << "Case " << t << ": ";

        // n=0일 때 특수 처리: 트리가 0개 (문제 정의상 0개는 No trees)
        // (n > 0 일 때도 num_trees == 0 이면 No trees)
        if (num_trees == 0) { 
            cout << "No trees.\n";
        } 
        // 트리가 한 개일 때
        else if (num_trees == 1) {
            cout << "There is one tree.\n";
        } 
        // 트리가 T개 (T > 1)일 때
        else {
            cout << "A forest of " << num_trees << " trees.\n";
        }
        
        t++;
    }
    return 0;
}