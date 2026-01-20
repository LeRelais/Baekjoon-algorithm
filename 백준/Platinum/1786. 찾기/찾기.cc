#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> find_lps(string p){
    vector<int> lps(p.length(), 0);
    int len = 0;
    
    for(int i = 1; i < p.length(); i++){
        while(len > 0 && p[i] != p[len]){
            len = lps[len-1];
        }
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
        }
    }
    
    return lps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string t, p;
    
    getline(cin, t);    
    getline(cin, p);
    
    vector<int> lps = find_lps(p);
    vector<int> res;
    int len = 0;
    for(int i = 0; i < t.length(); i++){
        while(len > 0 && t[i] != p[len]){
            len = lps[len-1];
        }
        if(t[i] == p[len]){
            if(len == p.length()-1){
                res.push_back(i - p.length() + 2);
                len = lps[len];
            }
            else{
                len++;
            }
        }
    }
    
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << '\n';
    }
    return 0;
}