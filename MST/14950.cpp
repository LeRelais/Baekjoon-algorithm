#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;

vector<pair<int, pair<int, int>>> edge;
int city[10001];

int getParent(int x) {
	if (city[x] == x) return x;
	else
		return city[x] = getParent(city[x]);
}

void Union(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px == py) return;

	if (px > py) city[px] = py;
	else
		city[py] = px;
}

vector<pair<int, pair<int, int>>> kruscal() {
	vector<pair<int, pair<int, int>>> mst;
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		int from = edge[i].second.first;
		int to = edge[i].second.second;

		if (getParent(from) == getParent(to)) continue;

		edge[i].first += cnt * t;
		mst.push_back(edge[i]);
		Union(from, to);

		if (mst.size() == n - 1) return mst;
		cnt++;
	}
}

int main() {
	cin >> n >> m >> t;
	int a, b, c;

	for (int i = 0; i <= n; i++)
		city[i] = i;

	while (m--) {
		cin >> a >> b >> c;
		edge.push_back({ c, {a, b} });
	}
	sort(edge.begin(), edge.end());

	vector<pair<int, pair<int, int>>> res = kruscal();

	int ans = 0;

	for (int i = 0; i < res.size(); i++) {
		ans += res[i].first;
	}

	cout << ans;

	return 0;
}