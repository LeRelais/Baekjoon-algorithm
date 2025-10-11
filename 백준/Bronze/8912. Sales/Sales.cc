#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        vector<int> cnt, arr;
        int n;
        cin >> n;
        cnt.resize(n, 0);
        arr.resize(n);
        int tmp;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[j] >= arr[i]){
                    cnt[j]++;
                }
            }
        }
        
        int res = 0;
        
        for(int i = 0; i < n; i++){
            res += cnt[i];
        }
        cout << res << endl;
    }
    return 0;
}