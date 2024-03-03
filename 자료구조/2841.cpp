#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, p, str_num, fret_num;
vector<stack<int>> v(7);

int main() {
    cin >> n >> p;
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> str_num >> fret_num;

        if (!v[str_num].empty() && v[str_num].top() > fret_num) {
            while (!v[str_num].empty() && v[str_num].top() > fret_num) {
                count++;
                v[str_num].pop();
            }
        }
        if (v[str_num].empty() || v[str_num].top() < fret_num) {
            count++;
            v[str_num].push(fret_num);
        }

    }
    cout << count;
    return 0;
}