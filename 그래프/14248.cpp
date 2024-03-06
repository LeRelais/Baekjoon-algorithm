#include <iostream>
#include <cstring>

using namespace std;

int n, s, count;
int arr[100001], dist[100001];

void dfs(int cur) {
    //cout << cur << endl;
    if (cur + arr[cur] >= 1 && cur + arr[cur] <= n) {
        if (dist[cur + arr[cur]] == -1) {
            dist[cur + arr[cur]] = 1;
            count++;
            dfs(cur + arr[cur]);
        }
    }
    if (cur - arr[cur] >= 1 && cur - arr[cur] <= n) {
        if (dist[cur - arr[cur]] == -1) {
            dist[cur - arr[cur]] = 1;
            count++;
            dfs(cur - arr[cur]);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> s;

    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    if (s >= 1 && s <= n) {
        dist[s] = 1;
        count = 1;
        dfs(s);
    }
    cout << count;
    return 0;
}