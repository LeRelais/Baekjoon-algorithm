#include <iostream>

using namespace std;

int primes[1001];

int main() {
    primes[1] = 1;
    
    for(int i = 2; i <= 1000; i++){
        for(int j = 2 * i; j <= 1000; j+=i){
            if(!primes[j])
                primes[j] = 1;
        }
    }
    
    int n, tmp, res = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        
        if(!primes[tmp])
            res++;
    }
    
    cout << res;
    return 0;
}