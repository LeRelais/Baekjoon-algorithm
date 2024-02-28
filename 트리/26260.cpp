#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

void postorder(int Left, int Right) {
    int mid = (Left + Right) / 2;
    if (mid - 1 >= Left)
        postorder(Left, mid - 1);
    if (mid + 1 <= Right)
        postorder(mid + 1, Right);

    cout << v[mid] << ' ';
}

int main() {
    cin >> n;

    int tmp, idx;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
        if (tmp == -1)
            idx = i;
    }

    cin >> tmp;
    v[idx] = tmp;

    sort(v.begin(), v.end());

    postorder(0, v.size() - 1);

}