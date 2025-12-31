#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, num, sum = 0, odd_cnt = 0, min_odd = 1001;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        sum += num;
        
        if(num % 2 == 1){
            odd_cnt += 1;
            min_odd = min(min_odd, num);
        }
    }
    
    if(odd_cnt % 2 == 1){
        sum -= min_odd;
    }
    
    cout << sum;
}