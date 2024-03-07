#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[100001];
int dist[100001];
int n, m, r, u, v, cnt = 1;

void dfs(int cur) {
    for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];

        if (next >= 1 && next <= n && dist[next] == 0) {
            cnt++;
            dist[next] = cnt;
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }


    dist[r] = cnt;

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << '\n';
    }
    return 0;
}