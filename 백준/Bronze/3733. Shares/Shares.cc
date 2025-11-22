#include <iostream>

using namespace std;

void solve() {
    int N;
    int S; 

    while (cin >> N >> S) {
        int total_people = N + 1;
        int max_shares_per_person = S / total_people;
        cout << max_shares_per_person << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}