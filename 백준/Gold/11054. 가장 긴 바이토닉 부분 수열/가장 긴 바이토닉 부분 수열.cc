#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp_inc[1001], dp_dec[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr;
    int n, num;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
        dp_inc[i] = 1;
        dp_dec[i] = 1;
    }
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j])
                dp_inc[i] = max(dp_inc[j] + 1, dp_inc[i]);
        }
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(arr[i] > arr[j]){
                dp_dec[i] = max(dp_dec[j] + 1, dp_dec[i]);
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(dp_inc[i] + dp_dec[i] - 1, res);
    }
    
    cout << res;
}