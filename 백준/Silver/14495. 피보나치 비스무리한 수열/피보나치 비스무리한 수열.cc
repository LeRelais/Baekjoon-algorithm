#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    
    vector<long long> fibo;
    
    cin >> n;
    if(n < 3)
        n = 3;
    fibo.resize(n+1);
    
    fibo[1] = 1;
    fibo[2] = 1;
    fibo[3] = 1;
    
    for(int i = 4; i <= n; i++){
        fibo[i] = fibo[i-1] + fibo[i-3];
    }
    
    cout << fibo[n];
    return 0;
}