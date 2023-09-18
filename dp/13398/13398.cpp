#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001];


int n, res = -987654321;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		res = max(res, dp[i]);
	}

	for (int i = 1; i <= n; i++) {
		int dp1[100001];
		if (i == 1) {
			dp1[2] = arr[2];
			for (int j = 3; j <= n; j++) {
				dp1[j] = max(arr[j], dp1[j - 1] + arr[j]);
				res = max(res, dp1[j]);
			}
		}
		else {
			int tmp = arr[i];
			arr[i] = -987654321;
			dp1[1] = arr[1];
			for (int j = 2; j <= n; j++) {
				if (arr[j] == -987654321)
					dp1[j] = dp1[j - 1];
				else {
					dp1[j] = max(dp1[j - 1] + arr[j], arr[j]);
					res = max(res, dp1[j]);
				}
			}
			arr[i] = tmp;
		}
		//for(int j = 1; j <= n; j++)
		//     cout << dp1[j] << ' ';
		// cout << endl;
	}
	cout << res;
	return 0;
}