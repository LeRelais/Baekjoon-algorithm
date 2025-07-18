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

int n, parent[100001];
int res;
vector<pair<int, pair<int, int>>> edge;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return;

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

long long min_d(long long a, long long b) {
	if (a > b) return b;
	else return a;
}

void Input() {
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		cin >> a >> b >> c;
		X.push_back({ a,i });
		Y.push_back({ b,i });
		Z.push_back({ c,i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < n - 1; i++) {
		edge.push_back({ X[i + 1].first - X[i].first, {X[i].second, X[i + 1].second} });
		edge.push_back({ Y[i + 1].first - Y[i].first, {Y[i].second, Y[i + 1].second} });
		edge.push_back({ Z[i + 1].first - Z[i].first, {Z[i].second, Z[i + 1].second} });
	}

	sort(edge.begin(), edge.end());
}

void Solve() {
	for (int i = 0; i < edge.size(); i++) {
		pair<double, pair<int, int>> curedge = edge[i];

		int f = curedge.second.first;
		int t = curedge.second.second;

		if (getParent(f) == getParent(t))
			continue;

		Union(f, t);
		res += curedge.first;
	}

	cout << res;
}
int main() {
	ios::sync_with_stdio(false);
	
	Input();
	Solve();
}
