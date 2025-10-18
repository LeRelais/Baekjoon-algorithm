#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int lan, ma;
    
    if(a % c == 0)
        lan = a / c;
    else
        lan = a / c + 1;
    
    if(b % d == 0)
        ma = b / d;
    else
        ma = b / d + 1;
    cout << l - max(lan, ma);
    return 0;
}