#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Task {
    string name;
    int start, play;
};

int toMin(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Task> tasks;
    for (auto& p : plans) tasks.push_back({p[0], toMin(p[1]), stoi(p[2])});
    
    // 1. 시작 시간순 정렬
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.start < b.start;
    });

    stack<pair<string, int>> st; // {과제명, 남은 시간}
    
    for (int i = 0; i < tasks.size(); i++) {
        // 마지막 과제는 무조건 일단 시작하면 끝남
        if (i == tasks.size() - 1) {
            answer.push_back(tasks[i].name);
            break;
        }

        int cur_start = tasks[i].start;
        int next_start = tasks[i+1].start;
        int playtime = tasks[i].play;
        int diff = next_start - cur_start; // 다음 과제까지 쓸 수 있는 시간

        if (playtime > diff) {
            // 다 못 끝내고 중단
            st.push({tasks[i].name, playtime - diff});
        } else {
            // 과제 완료
            answer.push_back(tasks[i].name);
            int remaining = diff - playtime; // 과제 끝내고 남은 시간
            
            // 남은 시간 동안 멈춰둔 과제 해결 (중요!)
            while (remaining > 0 && !st.empty()) {
                if (st.top().second <= remaining) {
                    remaining -= st.top().second;
                    answer.push_back(st.top().first);
                    st.pop();
                } else {
                    st.top().second -= remaining;
                    remaining = 0;
                }
            }
        }
    }

    // 모든 예정된 과제를 순회한 후 스택에 남은 것 처리
    while (!st.empty()) {
        answer.push_back(st.top().first);
        st.pop();
    }

    return answer;
}