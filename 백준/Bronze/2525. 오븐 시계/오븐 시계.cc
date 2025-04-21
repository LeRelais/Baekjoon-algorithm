#include <iostream>

using namespace std;

int main() {
    int h, m;
    int t;
    
    cin >> h >> m >> t;
    
    h += t/60;
    m += t%60;
    
    if(m >= 60){
        m -= 60;
        h += 1;
        
        //h %= 24;
    }
    
    cout << h%24 << ' ' << m;
    return 0;
}