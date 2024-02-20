#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int used[200001];
int arr[200001];

int main() {
    int n, city_num, parent;
    cin >> n;
    for (int i = 0; i < n; i++)
        used[i] = -2;

    cin >> city_num;
    used[city_num] = 1;
    arr[city_num] = -1;
    int count = 1;
    parent = city_num;

    for (int i = 1; i < n; i++) {
        cin >> city_num;

        if (used[city_num] == -2) {
            used[city_num] = 1;
            arr[city_num] = parent;
            parent = city_num;
            count++;
        }
        else {
            parent = city_num;
        }
    }

    cout << count << '\n';
    for (int i = 0; i < count; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}