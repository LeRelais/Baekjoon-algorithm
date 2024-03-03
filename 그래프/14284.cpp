#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> v[5001];
int cost[5001];
int n, m, a, b, c, s, t;

void solve() {
    while (!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if (cur == t) {
            cout << dist;
            break;
        }

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int n_cost = v[cur][i].second;

            if (dist + n_cost < cost[next]) {
                cost[next] = dist + n_cost;
                pq.push({ dist + n_cost, next });
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cost[i] = 99999999;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    cin >> s >> t;

    cost[s] = 0;
    pq.push({ 0, s });

    solve();
    return 0;
}