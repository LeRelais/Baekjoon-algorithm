#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << 1 / ((double)1 + pow(10, ((double)b-a)/400));
    return 0;
}