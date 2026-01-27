#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 정점 번호가 최대 1,000,000이므로 배열로 차수 관리
int inDegree[1000001];
int outDegree[1000001];

vector<int> solution(vector<vector<int>> edges) {
    set<int> nums; // 존재하는 모든 정점 번호를 저장
    
    for (const auto& edge : edges) {
        int from = edge[0];
        int to = edge[1];
        
        outDegree[from]++;
        inDegree[to]++;
        
        nums.insert(from);
        nums.insert(to);
    }

    int root = 0;
    int doughnut = 0, bar = 0, eight = 0;

    // 1. 생성된 정점(Root) 찾기
    // 존재하는 정점 번호들(nums)만 순회하므로 번호가 건너뛰어져도 안전함
    for (int i : nums) {
        if (inDegree[i] == 0 && outDegree[i] >= 2) {
            root = i;
            break;
        }
    }

    // 2. 각 그래프 모양의 특징적인 정점 카운트
    for (int i : nums) {
        if (i == root) continue; // 생성된 정점은 판별에서 제외

        // 막대 그래프: 나가는 간선이 0개인 노드가 반드시 1개 존재
        if (outDegree[i] == 0) {
            bar++;
        }
        // 8자 그래프: 나가는 간선이 2개이고 들어오는 간선이 2개 이상인 중심점이 1개 존재
        else if (outDegree[i] == 2 && inDegree[i] >= 2) {
            eight++;
        }
    }

    // 3. 도넛 그래프 계산
    // 생성된 정점에서 나간 총 간선 수 = 전체 그래프의 합
    doughnut = outDegree[root] - (bar + eight);

    return {root, doughnut, bar, eight};
}