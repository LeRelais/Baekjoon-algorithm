#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[1001];
int used[1001];
int n, m;

void search(int cur, int target, int total) {
    if (cur == target) {
        cout << total << '\n';
        return;
    }

    for (int i = 0; i < tree[cur].size(); i++) {
        if (!used[tree[cur][i].first]) {
            used[tree[cur][i].first] = 1;
            search(tree[cur][i].first, target, total + tree[cur][i].second);
            used[tree[cur][i].first] = 0;
        }
    }
}

int main() {
    cin >> n >> m;

    int point1, point2, dist;

    for (int i = 0; i < n - 1; i++) {
        cin >> point1 >> point2 >> dist;

        tree[point1].push_back({ point2, dist });
        tree[point2].push_back({ point1, dist });
    }

    for (int i = 0; i < m; i++) {
        cin >> point1 >> point2;
        used[point1] = 1;
        search(point1, point2, 0);
        used[point1] = 0;
    }
    return 0;
}