#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long calculate_happiness(int initial_value, int decrease_rate, int capacity) {
    long long total_happiness = 0;
    
    for (int i = 0; i < capacity; ++i) {
        long long current_happiness = (long long)initial_value - (long long)i * decrease_rate;
        
        if (current_happiness > 0) {
            total_happiness += current_happiness;
        } else {
            break;
        }
    }
    return total_happiness;
}

void solve() {
    int M, DM, H, DH;
    
    if (!(cin >> M >> DM)) return;
    
    if (!(cin >> H >> DH)) return;
    
    int N; 
    if (!(cin >> N)) return;

    long long max_total_happiness = 0;

    for (int i = 0; i < N; ++i) {
        int C, B; 
        if (!(cin >> C >> B)) return;
        
        long long cow_happiness = calculate_happiness(M, DM, C);
        long long bee_happiness = calculate_happiness(H, DH, B);
        max_total_happiness += max(cow_happiness, bee_happiness);
    }
    
    cout << max_total_happiness << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}