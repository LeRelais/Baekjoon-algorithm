#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    int tmp, max_val = 0, sum = 0, idx, res = 0;
    vector<int> arr;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        arr.push_back(tmp);
        max_val = max(max_val, tmp);
        sum += tmp;
    }
    
    int low = 1;
    int high = max_val;
    
    while(low <= high){
        int mid = (low + high) / 2;
        
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            cnt += arr[i] / mid;
            if(arr[i] % mid != 0)
                cnt++;
        }
        
        if(cnt <= n){
            idx = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << idx;
    return 0;
}