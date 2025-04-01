#include <iostream>

using namespace std;

int main() {
    int t, n, digit = 0;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n;
        
        for(int j = 1; j <= n; j*=2){
            if(n & j)
                cout << digit << ' ';
            digit++;
        }
        cout << '\n';
        digit = 0;
    }
    return 0;
}