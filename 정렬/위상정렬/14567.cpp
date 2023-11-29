#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
int n, m;
int arr[1001];
int nth[1001];
bool used[1001];
bool done() {
	for (int i = 1; i <= n; i++) {
		if (nth[i] == 0)
			return false;
	}
	return true;
}

int main() {
	cin >> n >> m;

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b] += 1;
	}

	int cnt = 1;
	while (1) {
		vector<int> tmp;
		if (done()) {
			break;
		}

		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0 && !used[i]) {
				used[i] = true;
				tmp.push_back(i);
				nth[i] = cnt;
			}
		}

		for (int i = 0; i < tmp.size(); i++) {
			int a = tmp[i];
			for (int j = 0; j < v[a].size(); j++) {
				arr[v[a][j]] -= 1;
			}
		}

		cnt++;
	}

	for (int i = 1; i <= n; i++) {
		cout << nth[i] << ' ';
	}
	return 0;
}