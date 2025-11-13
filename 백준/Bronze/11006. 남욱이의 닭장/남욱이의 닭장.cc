#include <iostream>

using namespace std;

void solve() {
    int T; 
    if (!(cin >> T)) return;
    for (int t = 0; t < T; ++t) {
        int N; 
        int M; 
        
        if (!(cin >> N >> M)) return;

        int T_intact = N - M;
        int U_cut = M - T_intact;
        cout << U_cut << " " << T_intact << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}