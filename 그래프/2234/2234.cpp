#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>

using namespace std;

int n, m;
int maze[51][51];
bool visited[51][51];
int roomSize;
int biggestRoom;

int wall[] = { 1, 2, 4, 8 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
void bfs(int col, int row) {
	int tmp = 1;
	visited[col][row] = true;
	queue<pair<int, int>> q;

	q.push({ col, row });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if ((maze[y][x] & wall[i]) == 0) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
					if (!visited[ny][nx]) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
						tmp++;
					}
				}
			}
		}
	}
	//cout << tmp << endl;
	roomSize = max(roomSize, tmp);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	int roomCount = 0;



	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				roomCount++;
			}
		}
	}

	cout << roomCount << '\n';
	cout << roomSize << '\n';

	roomSize = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if ((maze[i][j] & wall[k]) != 0) {
					memset(visited, false, sizeof(visited));
					maze[i][j] -= wall[k];
					bfs(i, j);
					maze[i][j] += wall[k];
				}
			}
		}
	}

	cout << roomSize;
	return 0;
}