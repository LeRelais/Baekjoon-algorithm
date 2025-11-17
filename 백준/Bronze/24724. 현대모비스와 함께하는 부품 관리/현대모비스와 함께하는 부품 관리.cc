#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Part {
    long long u; 
    long long v; 
};

bool compareParts(const Part& a, const Part& b) {
    return a.u < b.u;
}

void solve_test_case(int case_num) {
    int N; 
    if (!(cin >> N)) return;

    long long A, B; 
    if (!(cin >> A >> B)) return;

    vector<Part> parts(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> parts[i].u >> parts[i].v)) return;
    }

    cout << "Material Management " << case_num << "\n";

    
    sort(parts.begin(), parts.end(), compareParts);

    int group_count = 0;
    
    if (N > 0) {
        group_count = 1; // 최소 1개의 그룹은 필요
        long long current_size = 0;
        long long current_weight = 0;

        for (int i = 0; i < N; ++i) {
            long long next_size = parts[i].u;
            long long next_weight = parts[i].v;

            if (current_size + next_size <= A && current_weight + next_weight <= B) {
                current_size += next_size;
                current_weight += next_weight;
            } else {
                group_count++;
                current_size = next_size;
                current_weight = next_weight;
            }
        }
    }


    cout << "Classification ---- End!" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        solve_test_case(t);
    }

    return 0;
}