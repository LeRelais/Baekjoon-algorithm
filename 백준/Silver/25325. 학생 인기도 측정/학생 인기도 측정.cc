#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    string tmp;
    int n;
    
    map<string, int> fame;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        fame[tmp]++;
    }
    
    
    while(cin >> tmp){
        fame[tmp]++;
    }
    
    vector<pair<string, int>> fames(fame.begin(), fame.end());
    
    sort(fames.begin(), fames.end(), cmp);
    
    for(int i = 0; i < fames.size(); i++){
        cout << fames[i].first << ' ' << fames[i].second - 1 << '\n';
    }
    return 0;
}