#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[2000];
bool visited[2000];
int flag;

void dfs(int cur, int depth) {
    if (depth == 5)
    {
        flag = 1;
        return;
    }

    visited[cur] = true;
    // cout << cur << endl;

    for (int i = 0; i < v[cur].size(); i++) {
        if (!visited[v[cur][i]])
        {

            visited[v[cur][i]] = true;
            dfs(v[cur][i], depth + 1);
        }
    }
    visited[cur] = false;
    return;
}

int main() {
    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 1);
        if (flag)
            break;
    }
    cout << flag;
    return 0;
}