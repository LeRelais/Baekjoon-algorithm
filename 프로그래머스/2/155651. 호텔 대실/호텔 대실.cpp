#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// "HH:MM" -> 정수(분) 변환 함수
int toMinutes(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    // 1. 입실 시간 기준 정렬을 위해 변환된 데이터 생성
    vector<pair<int, int>> times;
    for (auto& book : book_time) {
        times.push_back({toMinutes(book[0]), toMinutes(book[1])});
    }
    sort(times.begin(), times.end());

    // 2. 우선순위 큐에는 "해당 방을 다시 사용할 수 있는 시각(퇴실+10분)" 저장
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto& t : times) {
        int start = t.first;
        int end = t.second + 10; // 청소 시간 포함

        if (!pq.empty() && pq.top() <= start) {
            // 가장 빨리 비는 방의 청소가 끝났다면, 그 방을 재사용
            pq.pop();
        }
        // 새 손님이 들어간 방의 '사용 가능해지는 시각' 추가
        pq.push(end);
    }

    return pq.size();
}