#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<long long, int> &a, const pair<long long, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

void solve(){
    map<long long, int> nums;
    
    int n;
    long long num;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        nums[num]++;
    }
    
    vector<pair<long long, int>> v = vector<pair<long long, int>>(nums.begin(), nums.end());
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}