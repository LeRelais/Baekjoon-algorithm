#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<int> v[1000000];
queue<pair<int,int>> q;
bool visited[1000000];
int n, m, k, x;
vector<int> res;

void bfs(int start) {
	visited[start] = true;
	q.push(make_pair(start, 0));
	

	while (!q.empty()) {
		int x = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (depth == k) {
			res.push_back(x);
		}
		
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];

			if (!visited[nx]) {
				visited[nx] = true;
				q.push(make_pair(nx, depth + 1));
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	bfs(x);

	if (res.size() == 0) {
		cout << -1;
		return 0;
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
}