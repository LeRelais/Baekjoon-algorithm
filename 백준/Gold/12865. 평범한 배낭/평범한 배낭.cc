#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
using namespace std;

int n, k, res;
int dp[101][100001];
int w[101];
int v[101];

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
}