#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    long long low = 1, high = 1000000000;
    cin >> n >> m;
    
    vector<int> pass;
    
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pass.push_back(tmp);
        high = min(high, (long long)tmp);
    }
    
    sort(pass.begin(), pass.end());
    
    long long res = 0;
    high *= m;
    while(low <= high){
        long long mid = (low + high) / 2;
        
        long long cnt = 0;
        
        for(int i = 0; i < pass.size(); i++){
            cnt += mid / pass[i];
            if(cnt >= m)
                break;
        }
        
        if(cnt >= m){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << res;
    return 0;
}