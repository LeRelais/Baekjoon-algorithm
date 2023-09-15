#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int n, m;
int dp[1001][1001];
int dp_left[1001][1001];
int dp_right[1001][1001];
int arr[1001][1001];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = -99999999;
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= m; i++) {
		dp[1][i] = dp[1][i - 1] + arr[1][i];
	}

	for (int i = 2; i <= n; i++) {

		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				dp_left[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else {
				dp_left[i][j] = max(dp[i - 1][j] + arr[i][j], dp_left[i][j - 1] + arr[i][j]);
			}

		}

		for (int j = m; j >= 1; j--) {
			if (j == m)
				dp_right[i][j] = dp[i - 1][j] + arr[i][j];
			else
				dp_right[i][j] = max(dp[i - 1][j] + arr[i][j], dp_right[i][j + 1] + arr[i][j]);

		}


		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp_left[i][j], dp_right[i][j]);

		}

	}


	cout << dp[n][m];
	return 0;
}