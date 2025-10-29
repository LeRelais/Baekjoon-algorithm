#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

typedef long long ll;
const ll INF = 4e18;

struct Line {
    ll m;
    ll b;
    
    // x_i를 대입하여 y 값을 계산 (b - m*x)
    ll eval(ll x) const {
        return b - m * x; 
    }
    
    // 두 직선의 교점 x 좌표 계산
    double intersectX(const Line& other) const {
        // x = (other.b - b) / (m - other.m)
        return (double)(other.b - b) / (m - other.m);
    }
};

// l2가 l1과 l3에 가려지는지 확인 (l2를 제거할 조건: l1,l2 교점이 l2,l3 교점보다 왼쪽에 있을 때)
bool check(const Line& l1, const Line& l2, const Line& l3) {
    // l1.intersectX(l2) >= l2.intersectX(l3)
    return l1.intersectX(l2) >= l2.intersectX(l3);
}

void solve() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return;

    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> x[i])) return;
    }

    vector<ll> dp(n, INF);
    dp[0] = 0;

    deque<Line> dq;

    // 초기 직선 삽입 (j=0)
    dq.push_back({2 * x[0], dp[0] + x[0] * x[0]});

    for (int i = 1; i < n; ++i) {
        // 1. 쿼리 (최적의 j 찾기): 현재 쿼리 x[i]보다 교점 x가 왼쪽에 있는 직선 제거
        while (dq.size() >= 2) {
            // dq[0]과 dq[1]의 교점이 x[i]보다 작으면 dq[0] 제거
            if (dq[0].intersectX(dq[1]) <= x[i]) {
                 dq.pop_front();
            } else {
                break;
            }
        }
        
        // 최적의 직선 (j) 선택
        Line best_line = dq.front();
        
        // 2. DP 갱신: DP[i] = x_i^2 + min_j(b - m*x_i)
        dp[i] = x[i] * x[i] + best_line.eval(x[i]);
        
        // 3. 삽입 (새로운 직선 i 추가)
        if (i == n - 1) break; // 마지막 노드는 삽입 불필요 (더 이상 점프하지 않음)

        Line new_line = {2 * x[i], dp[i] + x[i] * x[i]};
        
        // 덱의 뒤에서 볼록 껍질을 깨는 직선 제거
        while (dq.size() >= 2) {
            Line l1 = dq[dq.size() - 2];
            Line l2 = dq[dq.size() - 1];
            if (check(l1, l2, new_line)) {
                dq.pop_back();
            } else {
                break;
            }
        }
        dq.push_back(new_line);
    }

    cout << dp[n - 1] << '\n';
}

int main() {
    solve();
    return 0;
}