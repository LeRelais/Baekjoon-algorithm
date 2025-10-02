#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str, res = "{";
    cin >> str;
    
    for(int i = 1; i < str.length()-1; i++){
        for(int j = i+1; j < str.length(); j++){
            string s1 = str.substr(0, i);
            string s2 = str.substr(i, j-i);
            string s3 = str.substr(j);
            
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            reverse(s3.begin(), s3.end());
            
            string tmp = s1 + s2 + s3;
            
            if(res > tmp)
                res = tmp;
        }
    }    
    
    cout << res;
    return 0;
}