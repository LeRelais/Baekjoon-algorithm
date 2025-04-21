#include<vector>
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n, m;
int soldier[101][101];
bool visited[101][101];
int w_power, b_power;
int x_dir[4] = { 0,0,-1,1 };
int y_dir[4] = { -1,1,0,0 };

int bfs(int col, int row) {
	queue<pair<int, int>> q;
	visited[col][row] = true;
	q.push({ col, row });
	char tmp = soldier[col][row];
	int size = 1;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + x_dir[i];
			int ny = y + y_dir[i];

			if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
				if (!visited[ny][nx]) {
					if (soldier[ny][nx] == tmp) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
						size++;
					}
				}
			}
		}
	}
	return size * size;
}

int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			soldier[i][j] = s[j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				int res = bfs(i, j);
				if (soldier[i][j] == 'B')
					b_power += res;
				else
					w_power += res;
			}
		}
	}
	cout << w_power << ' ' << b_power;
}