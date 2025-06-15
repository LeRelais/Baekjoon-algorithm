#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>

using namespace std;

int t, f;
int parent[200001];
int set_size[200001];

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa != pb) {
		parent[pa] = pb;
		set_size[pb] += set_size[pa];
	}
}

void input() {
	cin >> t;
}

void solve() {
	while (t--) {
		map<string, int> m;
		int cnt = 0;
		cin >> f;
		string name1, name2;
		for (int i = 0; i < f; i++) {
			cin >> name1 >> name2;
			if (m.find(name1) == m.end()) {
				m[name1] = ++cnt;
				parent[cnt] = cnt;
				set_size[cnt] = 1;
			}
			if (m.find(name2) == m.end()) {
				m[name2] = ++cnt;
				parent[cnt] = cnt;
				set_size[cnt] = 1;
			}
			
			int pName1 = m[name1];
			int pName2 = m[name2];

			Union(pName1, pName2);

			cout << set_size[Find(pName1)] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(nullptr); cout.tie(nullptr);

	input();
	solve();
}