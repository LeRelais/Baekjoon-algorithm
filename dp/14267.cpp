#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100001];
int res[100001];
int parent[100001];
int n, m, i, w;

int solve(int cur) {
    if (cur == -1) return 0;
    if (res[cur] == -1)
        res[cur] = dp[cur];
    else
        return res[cur];
    return res[cur] += solve(parent[cur]);
}

int main() {
    cin >> n >> m;
    int tmp;

    for (i = 1; i <= n; i++) {
        cin >> tmp;
        parent[i] = tmp;
    }

    for (int j = 1; j <= m; j++) {
        cin >> i >> w;
        dp[i] += w;
    }

    memset(res, -1, sizeof(res));
    for (i = 1; i <= n; i++) {
        cout << solve(i) << ' ';
    }
    return 0;
}