#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> lis;
    vector<pair<int, int>>v;
    
    int n;
    cin >> n;
    
    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        
        auto iter = lower_bound(lis.begin(), lis.end(), tmp);
        
        if(iter == lis.end()){
            lis.push_back(tmp);
        }
        else{
            *iter = tmp;
        }
    }

    cout << lis.size();
    return 0;
}