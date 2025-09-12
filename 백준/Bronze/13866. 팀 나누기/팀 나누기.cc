#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int min_l = 99999, max_l = 0;
    
    int n;
    vector<int> arr;
    
    for(int i = 0; i < 4; i++){
        cin >> n;
        arr.push_back(n);    
    }
    
    sort(arr.begin(), arr.end());
    
    int team1 = arr[0] + arr[3];
    int team2 = arr[1] + arr[2];
    
    cout << abs(team1 - team2);

    return 0;
}