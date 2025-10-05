#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> tag;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    return a.second > b.second;
}

int main() {
    int n, t;
    cin >> n;
    string s, a, tag_name;
    
    while(n--){
        cin >> s >> t;
        
        for(int i = 0; i < t; i++){
            cin >> tag_name;
            tag[tag_name]++;
        }
    }
    
    vector<pair<string, int>> v(tag.begin(), tag.end());
    sort(v.begin(), v.end(), cmp);
    
    if(v[0].second != v[1].second){
        cout << v[0].first;
    }
    else
        cout << -1;
    
    return 0;
}