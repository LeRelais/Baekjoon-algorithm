#include <iostream>

using namespace std;

int main() {
    int B;
    if (!(cin >> B)) return 0;
    
    int P = 5 * B - 400;
    
    cout << P << '\n';
    
    int altitude_indicator;
    
    if (P < 100) {
        altitude_indicator = 1;
    } else if (P == 100) {
        altitude_indicator = 0;
    } else { // P > 100
        altitude_indicator = -1;
    }
    
    cout << altitude_indicator << '\n'; 

    return 0;
}