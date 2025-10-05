#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<char, int> &a, const pair<char, int> &b){
    return a.first < b.first;
}

bool cmp2(const pair<char, int> &a, const pair<char, int> &b){
    return a.second < b.second;
}

int main() {
    string pass_key, pass;
    cin >> pass_key >> pass;
    vector<pair<char, int>> sorted_key;
    vector<vector<pair<char, int>>> pass_v;
    
    for(int i = 0 ; i < pass_key.length(); i++){
        sorted_key.push_back({pass_key[i], i});
    }
    
    sort(sorted_key.begin(), sorted_key.end(), cmp);
    //cout << sorted_key[0].first << ' ' << sorted_key[0].second << '\n';
    pass_v.resize(pass.length() / pass_key.length(), vector<pair<char, int>>(pass_key.length()));
    //cout << pass_v.size();
    int r = pass.length() / pass_key.length(), c = pass_key.length();
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            pass_v[j][i] = {pass[i*r + j], sorted_key[i].second};
        }   
    }
    
    
    for(int i = 0; i < r; i++){
        sort(pass_v[i].begin(), pass_v[i].end(), cmp2);
    }
    
    string tmp ="";
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            tmp += pass_v[i][j].first;
    }
    
    cout << tmp;
    return 0;
}