#include <iostream>
#include <vector>
using namespace std;

int t;
int student[100001];
bool check[100001];
bool team[100001];

vector<int> candidate;
vector<vector<int>> adj(100001);

void dfs(int x, int target, int start) {
	if (start == target) {
		int tmp = 0;
		//cout << "x : " << x << " target : " << target << " start : " << start <<endl;
	   // cout << "print target: " << target << ' ' << candidate.size() << endl;

		for (int j = 0; j < adj[x].size(); j++) {
			//cout << "adj[x][j] : " << adj[x][j] << ' ';
			if (adj[x][j] == start)
				tmp = 1;
		}
		//cout << endl;
	   // cout << "tmp : " << tmp << endl;
		if (tmp) {
			team[target] = true;
			for (int i = 0; i < candidate.size(); i++)
				team[candidate[i]] = true;
		}
		return;
	}

	candidate.push_back(x);

	for (int i = 0; i < adj[x].size(); i++) {
		if (!check[adj[x][i]]) {
			check[adj[x][i]] = true;
			target = student[adj[x][i]];
			//cout << adj[x][i] << ' ' << target << ' ' << start << endl;
			dfs(adj[x][i], target, start);
			check[adj[x][i]] = false;
		}
	}

	candidate.pop_back();
}

int main() {
	cin >> t;

	int tmp;
	while (t--) {
		int res = 0;
		cin >> tmp;
		for (int i = 1; i <= tmp; i++) {
			cin >> student[i];
			adj[i].push_back(student[i]);
		}

		for (int i = 1; i <= tmp; i++) {
			if (!check[i]) {
				dfs(i, student[i], i);
			}
		}

		for (int i = 1; i <= tmp; i++) {
			if (team[i] == false)
				res++;
		}
		cout << res << endl;


		//cout << candidate.size() << endl;
	}
	return 0;
}