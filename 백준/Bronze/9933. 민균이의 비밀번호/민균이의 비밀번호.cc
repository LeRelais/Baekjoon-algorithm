#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    map<string, int> pass;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
       cin >> s; 
       pass[s] = 1;
    }

    string tmp;
    for(auto it = pass.begin(); it != pass.end(); it++){
        tmp = it->first;
        reverse(tmp.begin(), tmp.end());
        
        if(pass.find(tmp) != pass.end()){
            cout << (it->first).length() << ' ' << tmp[tmp.length()/2];
            
            break;
        }
    }
    return 0;
}