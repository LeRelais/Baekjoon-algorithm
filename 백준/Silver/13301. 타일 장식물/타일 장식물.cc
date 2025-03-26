#include <iostream>

using namespace std;

int dp_perimeter[81];
int dp_line[81];

int main() {
    int n;
    cin >> n;
    dp_perimeter[1] = 4;
    dp_line[1] = 1;
    dp_perimeter[2] = 6;
    dp_line[2] = 1;
    
    for(int i = 3; i <= n; i++){
        dp_line[i] = dp_line[i-1] + dp_line[i-2];
        dp_perimeter[i] = dp_line[i] * 4 + dp_line[i-1] * 2;
    }
    
    cout << dp_perimeter[n];
    return 0;
}