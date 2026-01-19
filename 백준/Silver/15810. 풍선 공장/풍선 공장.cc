#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    int cnt;
    long long max_t = 0;
    vector<int> t;
    
    for(int i = 0; i < n; i++){
        cin >> cnt;
        t.push_back(cnt);
        max_t = max(max_t, (long long)cnt);
    }
    
    long long high = max_t * m;
    long long res = high;
    long low = 0;
    
    while(low <= high){
        long long mid = (high + low) / 2;
        long long total = 0;
        
        for(int i = 0; i < n; i++){
            total += mid / t[i];
            if(total >= m)
                break;
        }
        
        if(total >= m){
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    
    cout << res;
    return 0;
}