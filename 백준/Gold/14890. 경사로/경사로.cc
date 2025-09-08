#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, l;

bool is_path_valid(const vector<int>& path) {
    int path_len = path.size();
    vector<bool> has_ramp(path_len, false);
    
    for (int i = 0; i < path_len - 1; ++i) {
        if (path[i] == path[i+1]) {
            continue;
        }
        
        // Case 1: Downward slope (path[i] > path[i+1])
        if (path[i] - path[i+1] == 1) {
            for (int j = 1; j <= l; ++j) {
                if (i + j >= path_len || path[i+j] != path[i+1] || has_ramp[i+j]) {
                    return false;
                }
                has_ramp[i+j] = true;
            }
        }
        
        // Case 2: Upward slope (path[i] < path[i+1])
        else if (path[i] - path[i+1] == -1) {
            for (int j = 0; j < l; ++j) {
                if (i - j < 0 || path[i-j] != path[i] || has_ramp[i-j]) {
                    return false;
                }
                has_ramp[i-j] = true;
            }
        }
        
        else { // Height difference > 1
            return false;
        }
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> l;
    
    vector<vector<int>> road(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> road[i][j];
        }
    }
    
    int result = 0;
    
    // Check all rows
    for (int i = 0; i < n; ++i) {
        if (is_path_valid(road[i])) {
            result++;
        }
    }
    
    // Check all columns
    for (int j = 0; j < n; ++j) {
        vector<int> col_path(n);
        for (int i = 0; i < n; ++i) {
            col_path[i] = road[i][j];
        }
        if (is_path_valid(col_path)) {
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}