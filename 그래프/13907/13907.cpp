#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k, s, d;
int dist[1001][1001];
vector<int> update;
vector<pair<int, int>> v[1001];
int a, b, cost;

int main() {
	cin >> n >> m >> k;
	cin >> s >> d;
	memset(dist, 0xf, sizeof(dist));

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;

		v[a].push_back({ b, cost });
		v[b].push_back({ a, cost });
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	dist[s][0] = 0;
	pq.push({ 0, {s, 0} });

	while (!pq.empty()) {
		int dis = pq.top().first;
		int x = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();

		if (dist[x][cnt] < dis || cnt >= n) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ndis = v[x][i].second;

			if (dist[nx][cnt + 1] > ndis + dis) {
				dist[nx][cnt + 1] = ndis + dis;
				pq.push({ dist[nx][cnt + 1], {nx, cnt + 1} });
			}
		}
	}


	int res = 987654321;

	for (int i = 1; i < n; i++) {
		res = min(res, dist[d][i]);
	}
	cout << res << '\n';

	int mul = 0;
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		mul += t;
		res = 987654321;

		for (int j = 1; j < n; j++) {
			//cout << mul << ' ';
			res = min(res, dist[d][j] + mul * j);
		}
		cout << res << '\n';
		//cout << endl;
	}
	return 0;
}