#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long low = 1, high = 1000000000, res;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long cnt = 0;
        
        for(int i = 1; i <= n; i++){
            cnt += min((mid / i), (long long)n);
            if(cnt >= k)
                break;
        }
        
        if(cnt >= k){
            high = mid - 1;
            res = mid;
        }
        else
            low = mid + 1;
    }
    cout << res;
    return 0;
}