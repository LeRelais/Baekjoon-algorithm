#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int tmp;
    vector<int> arr;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    int low = 0, high = 100000*10000;
    for(int x : arr) low = max(low, x);
    
    int res = 987654321;
    if(arr.size() == 1){
        cout << arr[0];
        return 0;
    }
    else{
        while(low <= high){
            int mid = (low + high) / 2;
            int cnt = 1, sum = 0;
            for(int i = 0; i < n; i++){
                if (sum + arr[i] > mid) {
                    cnt++;
                    sum = arr[i];
                } else {
                    sum += arr[i];
                }
            }
            
            //cout << mid << ' ' << cnt << ' ' << sum << endl;
            
            if(cnt > m){
                low = mid + 1;
            }
            else{
                res = mid;
                high = mid - 1;
            }
        }
    }
    cout << res;
    return 0;
}