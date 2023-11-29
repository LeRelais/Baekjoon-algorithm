#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> serial_num;

bool cmp(string& a, string& b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    int a_sum = 0, b_sum = 0;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9')
            a_sum += a[i] - '0';
        if (b[i] >= '0' && b[i] <= '9')
            b_sum += b[i] - '0';
    }

    if (a_sum != b_sum)
        return a_sum < b_sum;

    return a < b;
}

int main() {
    int n;
    string tmp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        serial_num.push_back(tmp);
    }

    sort(serial_num.begin(), serial_num.end(), cmp);

    for (int i = 0; i < serial_num.size(); i++) {
        cout << serial_num[i] << ' ';
    }
    return 0;
}