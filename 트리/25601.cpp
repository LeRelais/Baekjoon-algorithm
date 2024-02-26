#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<string, string> m;

int find(string a, string b) {
    while (a.size()) {
        if (a == b)
            return 1;
        a = m[a];
    }
    return 0;
}

int main() {
    cin >> n;
    string a, b;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        m[a] = b;
    }

    cin >> a >> b;

    if (find(a, b)) {
        cout << 1;
    }
    else if (find(b, a))
        cout << 1;
    else
        cout << 0;
    return 0;
}