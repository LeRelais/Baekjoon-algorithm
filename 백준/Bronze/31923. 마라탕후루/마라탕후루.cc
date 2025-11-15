#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int N, P, Q;
    if (!(cin >> N >> P >> Q)) return;

    vector<int> A(N); 
    vector<int> B(N); 
    vector<int> K(N); 

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int diff_rate = P - Q;
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        int initial_diff = B[i] - A[i];

        if (diff_rate == 0) {
            // Case 1: P = Q
            if (initial_diff != 0) {
                possible = false;
                break;
            }
            K[i] = 0;
        } else {
            if (initial_diff % diff_rate != 0) {
                possible = false;
                break;
            }

            int ki = initial_diff / diff_rate;
            
            if (ki < 0) {
                possible = false;
                break;
            }

            K[i] = ki;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
        for (int i = 0; i < N; ++i) {
            cout << K[i] << (i == N - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}