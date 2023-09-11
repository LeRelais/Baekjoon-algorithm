#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<vector>

using namespace std;

#define MAX 100001
int A, B, N, M;
bool visited[MAX];
int dir[6] = { -1, 1, -A, -B, A, B};
int mdir[2] = { A, B };
queue<pair<int, int>> q;
vector<int> res;

void bfs(int x) {
	visited[x] = true;
	q.push({ x,0 });
	
	while (!q.empty()) {
		int start = q.front().first;
		int count = q.front().second;
		q.pop();

		if (start == M)
			res.push_back(count);

		if (start + 1 < MAX && !visited[start + 1]) {
			visited[start + 1] = true;
			q.push({start+1, count+1});
		}
		if (start - 1 >= 0 && !visited[start - 1]) {
			visited[start - 1] = true;
			q.push({ start - 1, count + 1 });
		}
		if (start + A < MAX && !visited[start + A]) {
			visited[start + A] = true;
			q.push({ start + A, count + 1 });
		}
		if (start - A >= 0 && !visited[start - A]) {
			visited[start - A] = true;
			q.push({ start - A,count + 1 });
		}
		if (start + B < MAX && !visited[start + B]) {
			visited[start + B] = true;
			q.push({ start + B, count + 1 });
		}
		if (start - B >= 0 && !visited[start - B]) {
			visited[start - B] = true;
			q.push({ start - B, count + 1 });
		}
		if (start*A < MAX && !visited[start*A])
		{
			visited[start*A] = true;
			q.push({ start*A, count + 1 });
		}
		if (start*B < MAX && !visited[start*B])
		{
			visited[start*B] = true;
			q.push({ start*B, count + 1 });
		}
	}
}

int main() {
	cin >> A >> B >> N >> M;
	dir[2] = -A;
	dir[3] = -B;
	dir[4] = A;
	dir[5] = B;

	/*for (int i = 0; i < 6; i++) {
		cout << dir[i] << ' ';
	}*/

	bfs(N);

	sort(res.begin(), res.end());
	cout << res[0];
}