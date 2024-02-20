#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int k;
vector<int> building;
vector<int> building_depth[11];
int count;

void check(int Left, int Right, int depth) {
    if (depth == k + 1)
        return;

    int mid = (Left + Right) / 2;

    building_depth[depth].push_back(building[mid]);

    check(Left, mid - 1, depth + 1);
    check(mid + 1, Right, depth + 1);
}

int main() {
    cin >> k;
    building.push_back(0);

    int tmp;
    for (int i = 1; i <= pow(2, k) - 1; i++) {
        cin >> tmp;
        building.push_back(tmp);
    }

    check(1, pow(2, k) - 1, 1);

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < building_depth[i].size(); j++) {
            cout << building_depth[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}