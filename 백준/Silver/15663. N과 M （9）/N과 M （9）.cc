#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int nums[9];
int used[9];

map<vector<int>, int> seq;

void backtrack(int idx, vector<int> v){
    if(v.size() == m){
        seq.insert(pair<vector<int>, int>(v, 1));
        return;
    }
    for(int i = 0; i < n; i++){
        if(i != idx && !used[i]){
            used[i] = 1;
            v.push_back(nums[i]);
            backtrack(i, v);
            v.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    sort(nums, nums+n);
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = 1;
            v.push_back(nums[i]);
            backtrack(i, v);
            v.pop_back();
            used[i] = 0;
            
        }
    }
    
    for(auto i = seq.begin(); i != seq.end(); i++){
        for(int j = 0; j < i->first.size(); j++){
            cout << i->first[j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}