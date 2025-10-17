#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, k;
vector<int> parent;
vector<int> candy;
vector<int> number;
vector<int> group_roots;
vector<vector<int>> dp;

int getParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void make_union(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa != pb) {
        if (pa > pb) {
            parent[pa] = pb;
            candy[pb] += candy[pa];
            number[pb] += number[pa];
        } else {
            parent[pb] = pa;
            candy[pa] += candy[pb];
            number[pa] += number[pb];
        }
    }
}

void init() {
    if (!(cin >> n >> m >> k)) return; 

    parent.resize(n + 1);
    candy.resize(n + 1);
    number.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> candy[i];

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        number[i] = 1;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        make_union(a, b);
    }
    
    for (int i = 1; i <= n; i++) {
        getParent(i);
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) { 
            group_roots.push_back(i);
        }
    }
    
    dp.resize(group_roots.size() + 1, vector<int>(k, 0)); 
}

void solve() {
    for (int i = 1; i <= group_roots.size(); i++) {
        int root_node = group_roots[i - 1]; 
        int cost = number[root_node];
        int value = candy[root_node];

        for (int j = 1; j < k; j++) { 
            if (j >= cost) { 
                int not_select = dp[i - 1][j]; 
                int select = dp[i - 1][j - cost] + value; 
                dp[i][j] = max(select, not_select);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[group_roots.size()][k - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    solve();

    return 0;
}