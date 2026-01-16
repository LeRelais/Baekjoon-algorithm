#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    
    int min_pkg = 987654321, min_ind = 987654321;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        min_pkg = min(min_pkg, a);
        min_ind = min(min_ind, b);
    }
    
    int cnt = n / 6;
    if(n % 6 != 0){
        cout << min((cnt+1) * min_pkg, min(n * min_ind, cnt * min_pkg + (n % 6) * min_ind));
    }
    else{
        cout << min((cnt) * min_pkg, min(n * min_ind, cnt * min_pkg + (n % 6) * min_ind));
    }
}