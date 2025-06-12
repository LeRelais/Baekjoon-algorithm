#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<pair<int, int>> v;
	int a, b;
	while (n--) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<>> q;
	q.push(v[0].second);
	int cnt = 0;
	for (int i = 1; i < v.size(); i++) {
			if (q.top() > v[i].first) {
				q.push(v[i].second);
			}
			else {
				q.pop();
				q.push(v[i].second);
			}
	}

	cout << q.size();
}