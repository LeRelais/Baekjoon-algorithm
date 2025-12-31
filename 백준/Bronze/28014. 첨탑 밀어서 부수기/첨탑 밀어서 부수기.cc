#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    int prev, cur;
    
    cin >> prev;
    int cnt = 1;
    
    for(int i = 1; i < n; i++){
        cin >> cur;
        
        if(prev <= cur){
            cnt++;
        }
        
        prev = cur;
    }
    
    cout << cnt;
    return 0;
}