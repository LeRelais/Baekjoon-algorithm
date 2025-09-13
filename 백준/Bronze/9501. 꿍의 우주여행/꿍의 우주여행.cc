#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, d;
    float v, f, c;
    while(t--){
        int res = 0;
        cin >> n >> d;
        for(int i = 0; i < n; i++){
            cin >> v >> f >> c;
            
            if((float)d <= v * f / c)
                res++;
        }
        cout << res << '\n';
    }
    return 0;
}