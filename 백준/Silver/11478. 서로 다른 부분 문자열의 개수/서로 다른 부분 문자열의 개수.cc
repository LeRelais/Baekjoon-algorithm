#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    int res = 0;
    map<string, int> sub_str;
    cin >> s;
    
    for(int i = 0; i < s.length(); i++){
        string tmp = "";
        
        for(int j = i; j < s.length(); j++){
            tmp += s[j];
            
            if(sub_str.find(tmp) == sub_str.end()){
                sub_str[tmp]++;
                res++;
            }
        }
    }
    
    cout << res;
    return 0;
}