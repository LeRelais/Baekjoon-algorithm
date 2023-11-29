#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int t, n, k;
int arr[1001];
int cnt[1001];
int dp[1001];

bool flag() {
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != 0)
			return false;
	}
	return true;
}

int main() {
	cin >> t;
	int a, b, w;
	while (t--) {
		queue<int> q;
		vector<int> v[1001];
		cin >> n >> k;
		memset(dp, 0, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			cnt[b] += 1;
		}

		cin >> w;

		for (int i = 1; i <= n; i++) {
			if (!cnt[i])
				q.push(i);
			dp[i] = arr[i];
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < v[x].size(); i++) {
				cnt[v[x][i]] -= 1;
				dp[v[x][i]] = max(dp[v[x][i]], dp[x] + arr[v[x][i]]);

				if (cnt[v[x][i]] == 0)
					q.push(v[x][i]);
			}
		}
		cout << dp[w] << '\n';
	}
	return 0;
}