#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    vector<int> arr(n, 0);
    vector<int> sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum[i+1] = arr[i];
    }
    
    for(int i = 1; i <= n; i++){
        sum[i] += sum[i-1];
    }
    
    int a, b;
    while(m--){
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
}