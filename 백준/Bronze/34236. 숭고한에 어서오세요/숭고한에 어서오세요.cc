#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> years;
    
    int n, year;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> year;
        years.push_back(year);
    }
    
    cout << years[n-1] + (years[n-1]-years[n-2]);
    return 0;
}