#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001][2];


int n, res;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1][0] = dp[1][1] = arr[1];
	res = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);    //이건 안빼고 그대로 진행했을 때의 누적합
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]); //이건 i번째 수를 뺐을 때의 누적합. 
		res = max(res, max(dp[i][0], dp[i][1]));
	}

	cout << res;
	return 0;
}