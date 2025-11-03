#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<int> A(N);
    vector<int> B(M);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    sort(B.begin(), B.end()); 

    long long total_pairs = 0; 

    for (int i = 0; i < N; ++i) {
        int target = A[i];
        auto it = upper_bound(B.begin(), B.end(), target); 

       
        auto lower_it = lower_bound(B.begin(), B.end(), target); 
        total_pairs += (lower_it - B.begin());
        
    }

    cout << total_pairs << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}