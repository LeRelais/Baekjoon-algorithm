#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    vector<vector<int>> arr(n+1, vector<int>(n, 0));
    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = arr[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    
    
    int r1, c1, r2, c2;
    for(int k = 0; k < m; k++){
        cin >> r1 >> c1 >> r2 >> c2;
        cout << sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1] << '\n';
    }
}