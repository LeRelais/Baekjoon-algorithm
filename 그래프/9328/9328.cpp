#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char maze[101][101];
bool key[26];
bool visited[101][101];
int t, h, w, res;

typedef struct _data {
	int y;
	int x;
} DATA;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void bfs(int col, int row) {
	queue<DATA> q;
	queue<DATA> door[26];
	q.push({ col, row });
	visited[col][row] = true;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
				if (!visited[ny][nx] && maze[ny][nx] != '*') {
					visited[ny][nx] = true;

					if ('A' <= maze[ny][nx] && maze[ny][nx] <= 'Z') {
						if (key[maze[ny][nx] - 'A'])
							q.push({ ny,nx });
						else
							door[maze[ny][nx] - 'A'].push({ ny,nx });
					}
					else if ('a' <= maze[ny][nx] && maze[ny][nx] <= 'z') {
						q.push({ ny,nx });
						if (!key[maze[ny][nx] - 'a'])
						{
							key[maze[ny][nx] - 'a'] = true;
							while (!door[maze[ny][nx] - 'a'].empty()) {
								q.push(door[maze[ny][nx] - 'a'].front());
								door[maze[ny][nx] - 'a'].pop();
							}
						}
					}
					else {
						q.push({ ny,nx });
						if (maze[ny][nx] == '$')
							res++;
					}
				}
			}
		}
	}
}

int main() {
	string s;
	cin >> t;

	while (t--) {
		vector<pair<int, int>> tmp;
		res = 0;
		memset(visited, false, sizeof(visited));
		memset(key, false, sizeof(key));
		cin >> h >> w;
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				maze[i][j] = s[j];
				if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
					if (maze[i][j] == '.' || maze[i][j] == '$')
						tmp.push_back({ i,j });
				}
			}
		}
		cin >> s;
		//cout << tmp.size();
		for (int i = 0; i < s.length(); i++) {
			key[s[i] - 'a'] = 1;
		}

		for (int i = 0; i < tmp.size(); i++) {
			bfs(tmp[i].first, tmp[i].second);
		}
		cout << res << '\n';
	}
	return 0;
}