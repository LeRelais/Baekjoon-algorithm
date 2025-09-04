#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w, n, m, a, b;
    
    cin >> h >> w >> n >> m;
    
    if( h % (n+1) != 0){
        a = h / (n+1) + 1;
    }
    else
        a = h / (n+1); 

    if( w % (m+1) != 0){
        b = w / (m+1) + 1;
    }
    else
        b = w / (m+1); 
        
    cout << a * b;
}