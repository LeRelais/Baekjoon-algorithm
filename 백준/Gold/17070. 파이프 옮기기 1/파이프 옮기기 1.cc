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

int n, arr[17][17], cnt;
bool visited[17][17];

struct cord {
	int y1, x1;
	int y2, x2;
};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs() {
	queue<cord> q;
	visited[0][0] = true;
	visited[0][1] = true;
	q.push({ 0,0,0,1 });

	while (!q.empty()) {
		int y1 = q.front().y1;
		int x1 = q.front().x1;
		int y2 = q.front().y2;
		int x2 = q.front().x2;
		q.pop();

		if (y2 == n - 1 && x2 == n - 1) {
			cnt++;
			continue;
		}

		if (y1 == y2 && x1 + 1 == x2) {
			int ny = y2;
			int nx = x2 + 1;

			if (arr[ny][nx] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });

			ny = y2 + 1;
			nx = x2 + 1;

			if (arr[ny][nx] != 1 && arr[ny - 1][nx] != 1 && arr[ny][nx - 1] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });
		}
		else if (y1 + 1 == y2 && x1 == x2) {
			int ny = y2 + 1;
			int nx = x2;

			if (arr[ny][nx] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });

			ny = y2 + 1;
			nx = x2 + 1;

			if (arr[ny][nx] != 1 && arr[ny - 1][nx] != 1 && arr[ny][nx - 1] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });
		}
		else {
			int ny = y2;
			int nx = x2 + 1;

			if (arr[ny][nx] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });

			ny = y2 + 1;
			nx = x2;

			if (arr[ny][nx] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });

			ny = y2 + 1;
			nx = x2 + 1;

			if (arr[ny][nx] != 1 && arr[ny - 1][nx] != 1 && arr[ny][nx - 1] != 1 && nx < n && ny < n)
				q.push({ y2,x2,ny,nx });
		}
	}
	cout << cnt;
}

void solve() {
	bfs();
}

int main() {
	ios::sync_with_stdio(false);
	input();
	solve();
}