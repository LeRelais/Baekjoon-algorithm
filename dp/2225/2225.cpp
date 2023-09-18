#include <iostream>

using namespace std;

int n, k;

long long dp[201][201];   // n == target 숫자  k == k개 써서 target을 만들었다

int main() {
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int j = 2; j <= k; j++) {
		for (int i = 0; i <= n; i++) {
			for (int x = 0; x <= i; x++) {
				dp[j][i] += dp[j - 1][x];
			}
		}
	}

	cout << dp[k][n];
	return 0;
}