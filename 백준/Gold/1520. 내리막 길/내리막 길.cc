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

int m, n, res;
int arr[501][501];
int dp[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = {-1, 1, 0, 0};

void input() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
			cin >> arr[i][j];
		}
	}
}

int move(int y, int x) {
	if (y == m - 1 && x == n - 1)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1) {
		return ret;
	}
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (arr[ny][nx] < arr[y][x])
			ret += move(ny, nx);
	}
	return ret;
}

void solve() {
	cout << move(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	
	input();
	solve();
}