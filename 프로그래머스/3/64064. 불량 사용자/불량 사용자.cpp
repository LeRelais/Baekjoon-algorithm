#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> candidates; // 각 banned_id 위치별 가능한 user_idx들
bool visited[8];
set<set<int>> s; // 결과를 set<int>로 저장하면 내부에서 자동 정렬되어 중복 체크가 쉽습니다

void dfs(int cur, set<int>& collected) {
    if (cur == N) {
        s.insert(collected); // 인덱스 구성이 같으면 동일한 것으로 처리됨
        return;
    }

    for (int user_idx : candidates[cur]) {
        if (!visited[user_idx]) {
            visited[user_idx] = true;
            collected.insert(user_idx);
            
            dfs(cur + 1, collected);
            
            // 백트래킹
            collected.erase(user_idx);
            visited[user_idx] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // 전역 변수 초기화 (중요)
    N = banned_id.size();
    candidates.assign(N, vector<int>());
    s.clear();
    for(int i=0; i<8; i++) visited[i] = false;

    // 1. 매칭 단계 (인덱스 기반 저장)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (user_id[j].length() != banned_id[i].length()) continue;
            
            bool match = true;
            for (int k = 0; k < user_id[j].length(); k++) {
                if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]) {
                    match = match = false;
                    break;
                }
            }
            if (match) candidates[i].push_back(j);
        }
    }

    // 2. DFS 탐색
    set<int> current_collected;
    dfs(0, current_collected);

    return s.size();
}