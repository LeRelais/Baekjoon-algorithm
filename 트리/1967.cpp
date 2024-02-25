#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, tmp_node, tmp_dist;
vector<pair<int, int>> v[10001];

int used[10001];

void dfs(int start, int dist) {
    used[start] = true;
    // cout << start << '\n';
    if (dist > tmp_dist) {
        tmp_node = start;
        tmp_dist = dist;
    }
    // if(used[start])
    //     return;

    for (int i = 0; i < v[start].size(); i++) {
        int nx = v[start][i].first;
        if (!used[nx]) {
            used[nx] = true;
            dfs(nx, dist + v[start][i].second);
            used[nx] = false;
        }
    }
}

int main() {
    cin >> n;

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }

    dfs(1, 0);
    memset(used, false, sizeof(used));
    dfs(tmp_node, 0);
    cout << tmp_dist;
    return 0;
}