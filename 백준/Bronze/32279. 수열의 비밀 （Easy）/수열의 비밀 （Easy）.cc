#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long N;
long long P, Q, R, S;
long long A1;
map<long long, long long> memo;
long long total_sum = 0;

long long calculate_a(long long i) {
    if (memo.count(i)) {
        return memo[i];
    }
    if (i > N) {
        return 0;
    }

    long long current_val;
    
    if (i == 1) {
        current_val = A1;
    } 
    else if (i % 2 == 0) {
        current_val = P * calculate_a(i / 2) + Q;
    } 
    else {
        current_val = R * calculate_a((i - 1) / 2) + S;
    }

    memo[i] = current_val;
    total_sum += current_val;

    return current_val;
}

void solve() {
    if (!(cin >> N)) return;
    if (!(cin >> P >> Q >> R >> S)) return;
    if (!(cin >> A1)) return;

    total_sum = 0;
    memo.clear();

    memo[1] = A1;
    total_sum += A1;

    for (long long i = 2; i <= N; ++i) {
        calculate_a(i);
    }
    
    cout << total_sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}