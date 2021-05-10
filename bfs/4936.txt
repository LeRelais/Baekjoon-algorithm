#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdlib>

using namespace std;

int map[51][51];
bool visited[51][51];
int x_dir[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int y_dir[8] = { -1, -1, 0, 1,1, 1,0, -1 };
int cnt, col, row;

void bfs(int h, int w) {
	queue<pair<int, int>> q;
	visited[h][w] = true;
	q.push(make_pair(h, w));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + x_dir[i];
			int ny = y + y_dir[i];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
				if (!visited[ny][nx] && map[ny][nx] == 1) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	while (true) {
		cin >> row >> col;
		cnt = 0;

		if (row == 0 && col == 0)
			break;

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}