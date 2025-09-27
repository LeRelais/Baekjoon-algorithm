#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, h;

int main() {
    cin >> n >> h;
    vector<int> v;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    int res = 0;
    for(int i = 0; i < n; i++){
        if(v[i] <= h)
            res++;
    }
    cout << res;
    return 0;
}