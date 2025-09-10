#include <iostream>

using namespace std;

long long fpow(long long t, long long e, long long divider){
    if(e == 1)
        return t;
    else{
        long long x = fpow(t, e/2, divider);
        long long x_square = (x * x) % divider;
        if(e % 2 == 0){
            return (x_square + divider) % divider;
        }
        else{
            return (((x_square + divider) % divider) * t + divider ) % divider;
        }
    }
}

int main() {
    long long a, b, c;
    
    cin >> a >> b >> c;
    
    long long res = fpow(a, b, c);
    
    cout << (res % c);
    
    return 0;
}