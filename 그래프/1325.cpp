#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include <stdio.h>
#include<set>
#include <string.h>
#include<math.h>
using namespace std;

vector<int> v[100000+1];
int cnt;
bool visited[100000 + 1];

void dfs(int start) {
	if (visited[start])
		return;
	visited[start] = true;
	cnt++;
	for (int i = 0; i < v[start].size(); i++) {
		int a = v[start][i];
		dfs(a);
	}
}

int main() {
	int n, m, a, b;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	int depth[100000 + 1];
	
	for (int i = 1; i <= n; i++) {
		memset(visited, false, 100001);
		cnt = 0;
		dfs(i);
		depth[i] = cnt;
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (depth[i] > max)
			max = depth[i];
	}

	for (int i = 1; i <= n; i++) {
		if (max == depth[i])
			cout << i << " ";
	}
}