#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

int map[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
int x_dir[4] = { 0, 1, 0, -1 };
int y_dir[4] = { -1, 0, 1, 0 };
int m, n, flag;

void bfs(int y, int x) {
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int curx = q.front().second;
		int cury = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + x_dir[i];
			int ny = cury + y_dir[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (!visited[ny][nx] && map[ny][nx] == 0) {
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	string s;

	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}

/*	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}*/

	for (int j = 0; j < n; j++) {
		if (map[0][j] == 0 && !visited[0][j])
			bfs(0, j);
	}
	flag = 0;
	for (int i = 0; i < n; i++) {
		if (visited[m - 1][i] == true) {
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}