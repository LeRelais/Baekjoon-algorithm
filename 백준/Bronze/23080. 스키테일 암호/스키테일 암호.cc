#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k, idx = 0;
    string str, password;
    
    cin >> k >> str;
    
    while(idx < str.length()){
        password += str[idx];
        idx += k;
    }
    
    cout << password;
}