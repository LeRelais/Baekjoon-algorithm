#include <iostream>

using namespace std;

long long fpow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n == 1) {
            cout << 1 << '\n';
        } else {
            cout << fpow(2, n - 2, 1000000007) << '\n';
        }
    }

    return 0;
}