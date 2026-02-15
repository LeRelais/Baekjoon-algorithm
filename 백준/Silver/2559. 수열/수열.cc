#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    
    vector<int> arr(n, 0);
    vector<int> sum(n+1, 0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum[i+1] = arr[i];
    }
    for(int i = 1; i <= n; i++){
        sum[i] += sum[i-1];
    }
    
    int res = 100000*-100;
    for(int i = k; i <= n; i++){
        res = max(res, sum[i] - sum[i-k]);
    }
    cout << res;
}