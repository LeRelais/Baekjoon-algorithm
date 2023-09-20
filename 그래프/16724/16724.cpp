#include <iostream>
#include <string>

using namespace std;

int n, m;
char arr[1001][1001];
int visited[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int Num = 1;
int parent[250001];
int cnt = 0;

void dfs(int col, int row) {
	visited[col][row] = 1;
	int ny, nx, tmp;

	if (arr[col][row] == 'D') {
		ny = col + dy[1];
		nx = row + dx[1];
	}
	else if (arr[col][row] == 'U') {
		ny = col + dy[0];
		nx = row + dx[0];
	}
	else if (arr[col][row] == 'L') {
		ny = col + dy[2];
		nx = row + dx[2];
	}
	else if (arr[col][row] == 'R') {
		ny = col + dy[3];
		nx = row + dx[3];
	}

	if (visited[ny][nx] == 1) cnt++;
	if (visited[ny][nx] == 0) dfs(ny, nx);

	visited[col][row] = 2;
}

int main() {
	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
			}
		}
	}

	cout << cnt;


	return 0;
}