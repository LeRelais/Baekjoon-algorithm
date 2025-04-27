#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int arr[16], n;
    
    arr[0] = 2;
    
    for(int i = 1; i <= 15; i++)
        arr[i] = arr[i-1] + pow(2, i-1);
    
    cin >> n;
    
    cout << arr[n] * arr[n];
}