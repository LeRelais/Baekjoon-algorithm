#include <iostream>
#include <algorithm>

using namespace std;

int ropes[100001], n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> ropes[i];

    sort(ropes, ropes + n);

    int maxWeight = 0, idx = 0;

    for (int i = n; i > 0; i--) {
        if (maxWeight < ropes[idx] * i)
            maxWeight = ropes[idx] * i;
        idx++;
    }
    cout << maxWeight;
    return 0;
}