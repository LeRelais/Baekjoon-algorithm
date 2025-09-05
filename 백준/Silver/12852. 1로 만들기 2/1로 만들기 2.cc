#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

const int INF = 987654321; // 무한대를 나타내는 큰 값

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // dp[i] : i를 1로 만드는 최소 연산 횟수
    // trace[i] : i로 가기 직전의 수
    vector<int> dp(n + 1, INF);
    vector<int> trace(n + 1, 0);

    dp[1] = 0;

    for (int i = 1; i < n; ++i) {
        // 현재 수 i에서 1을 더하는 연산
        if (dp[i] + 1 < dp[i + 1]) {
            dp[i + 1] = dp[i] + 1;
            trace[i + 1] = i;
        }

        // 현재 수 i에서 2를 곱하는 연산
        if (i * 2 <= n && dp[i] + 1 < dp[i * 2]) {
            dp[i * 2] = dp[i] + 1;
            trace[i * 2] = i;
        }
        
        // 현재 수 i에서 3을 곱하는 연산
        if (i * 3 <= n && dp[i] + 1 < dp[i * 3]) {
            dp[i * 3] = dp[i] + 1;
            trace[i * 3] = i;
        }
    }

    // 결과 출력
    cout << dp[n] << '\n';

    // 경로 역추적 및 출력
    deque<int> path;
    int current = n;
    while (current != 0) {
        path.push_back(current);
        current = trace[current];
    }
    
    while (!path.empty()) {
        cout << path.front() << " ";
        path.pop_front();
    }
    cout << '\n';

    return 0;
}