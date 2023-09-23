#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first < b.first)
			return true;
		if (a.first == b.first) {
			if (a.second < b.second)
				return true;
			return false;
		}
		return false;
	}
};

int main() {
	priority_queue<int, vector<int>, less<int>> pq;
	vector<pair<int, int>> v;
	cin >> n;

	int d, w, t = 0;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		t = max(t, d);
		v.push_back({ d, w });
	}

	sort(v.begin(), v.end());


	int res = 0;
	int idx = n - 1;

	for (int i = t; i >= 1; i--) {
		while (v[idx].first == i) {
			pq.push(v[idx].second);
			idx--;
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
	return 0;
}