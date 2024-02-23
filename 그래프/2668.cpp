#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
bool flag;
int arr[101], used[101];
vector<int> v;

void dfs(int start, int next) {
    if (used[next] == 1) {
        if (start == next) {
            v.push_back(start);
            v.push_back(next);
            flag = true;
        }
        return;
    }

    used[next] = 1;
    dfs(start, arr[next]);

    if (flag) {
        v.push_back(start);
        v.push_back(next);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        used[i] = 1;
        dfs(i, arr[i]);
        // for(int j = 1; j <= n; j++){
        //     cout << used[j] << ' ';
        // }
        // cout << endl;
        memset(used, false, sizeof(used));
        flag = false;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());


    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}