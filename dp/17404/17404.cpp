#include <iostream>
#include <algorithm>

using namespace std;

int cost[1001][3];
int n;

int main() {
	cin >> n;

	int c1, c2, c3;
	int res = 99999999;

	for (int i = 1; i <= n; i++) {
		cin >> c1 >> c2 >> c3;
		cost[i][0] = c1;
		cost[i][1] = c2;
		cost[i][2] = c3;
	}

	for (int start = 0; start < 3; start++) {
		int dp[1001][3];
		for (int i = 0; i < 3; i++) {
			if (start == i)
				dp[1][i] = cost[1][i];
			else
				dp[1][i] = 99999999;
		}

		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}
		for (int i = 0; i < 3; i++) {
			if (i == start) continue;
			res = min(res, dp[n][i]);
		}
	}
	cout << res;
	return 0;
}