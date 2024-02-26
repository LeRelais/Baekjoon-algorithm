#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> graphs[101];
int arr[101];

void search(int x) {
    for (int i = 0; i < graphs[x].size(); i++) {
        if (!arr[graphs[x][i]]) {
            arr[graphs[x][i]] = 1;
            search(graphs[x][i]);
        }
    }
}

int main() {
    cin >> n;

    int tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp == 1) {
                graphs[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        memset(arr, false, sizeof(arr));
        search(i);
        for (int j = 0; j < n; j++)
            cout << arr[j] << ' ';
        cout << '\n';
    }

    return 0;
}