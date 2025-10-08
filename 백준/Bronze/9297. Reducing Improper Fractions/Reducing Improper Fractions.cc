#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;

  for (int i = 1; i <= t; i++) {
    int num, den; cin >> num >> den;

    int quotient = num / den;
    num %= den;

    cout << "Case " << i << ": ";

    if (quotient == 0) {
      if (num == 0) cout << "0\n";
      else cout << num << "/" << den << "\n";
    } else {
      if (num == 0) cout << quotient << "\n";
      else cout << quotient << " " << num << "/" << den << "\n";
    }
  }

  return 0;
}