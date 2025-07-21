#include <iostream>
#include <algorithm>

using namespace std;

int prefix_sum[11];

int main() {
    int n, res = 0, diff = 987654321;
    
    for(int i = 0; i < 10; i++){
        cin >> n;
        if(i != 0)
            prefix_sum[i] = prefix_sum[i-1] + n;
        else
            prefix_sum[i] = n;
    }
    
    for(int i = 0; i < 10; i++){
        if(diff >= abs(100 - prefix_sum[i])){
            diff = abs(100 - prefix_sum[i]);
            res = max(res, prefix_sum[i]);
        }
    }
    
    cout << res;
    return 0;
}