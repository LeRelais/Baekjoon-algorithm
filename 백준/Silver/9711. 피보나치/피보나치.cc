#include <iostream>

using namespace std;

int t, p;
long long q;
long long fibo[10001];
int main() {
    cin >> t;
    
    fibo[1] = 1;
    fibo[2] = 1;
    
    for(int i = 1; i <= t; i++){
        cin >> p >> q;
        
        for(int j = 3; j <= p; j++){
            fibo[j] = (fibo[j-1] + fibo[j-2]) % q;
        }
        
        printf("Case #%d: %lld\n", i, (fibo[p] % q));
    }
    
    return 0;
}