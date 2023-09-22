#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, l;

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	long long tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		pq.push({ tmp, i });

		while (pq.top().second < i - l + 1)
			pq.pop();

		cout << pq.top().first << ' ';
	}

	return 0;
}