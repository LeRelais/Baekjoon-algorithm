#include <iostream>
#include <map>
#include <math.h>

using namespace std;

map<long long, long long> m;
long long n, p, q;

long long solve(long long n) {
    if (m.find(n) != m.end())
        return m[n];

    long long res = solve(n / p) + solve(n / q);
    m[n] = res;
    return m[n];
}

int main() {
    cin >> n >> p >> q;
    m[0] = 1;

    if (n == 0)
        cout << 1;
    else
        cout << solve(n / p) + solve(n / q);
    return 0;
}