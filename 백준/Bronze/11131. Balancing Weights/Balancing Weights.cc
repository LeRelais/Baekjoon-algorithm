#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return; 

    long long total_torque_sum = 0; 
    
    for (int i = 0; i < N; ++i) {
        int Wi;
        if (!(cin >> Wi)) return;
        
        total_torque_sum += Wi;
    }

    if (total_torque_sum < 0) {
        cout << "Left" << endl;
    } else if (total_torque_sum > 0) {
        cout << "Right" << endl;
    } else {
        cout << "Equilibrium" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        solve();
    }

    return 0;
}