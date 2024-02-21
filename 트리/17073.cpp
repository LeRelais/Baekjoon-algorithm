#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes[500001];
int used[500001];
int n;
double w;

int main() {
    cin >> n >> w;

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    int leaf = 0;

    for (int i = 2; i <= n; i++) {
        if (nodes[i].size() == 1) {
            leaf++;
        }
    }

    cout.precision(6); cout << fixed << w / leaf << endl;
    return 0;
}