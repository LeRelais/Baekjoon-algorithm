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

queue<pair<int, int>> q;
int n, k;

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> k;

	int *a = new int[n];
	bool *visited = new bool[k+1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q.push({ 1, a[i] });
	}

	int res = -99999999;
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x == k) {
			res = cnt;
			break;
		}
		for (int i = 0; i < n; i++) {
			int nx = x + a[i];

			if (!visited[nx] && nx <= k) {
				visited[nx] = true;
				q.push({ cnt + 1, nx });
			}
		}
	}

	if (res == -99999999)
		cout << -1;
	else
		cout << res;
}
