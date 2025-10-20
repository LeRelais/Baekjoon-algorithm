#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    string str;
    
    while(t--){
        cin >> str;
        int error_count = 0;
        int len = str.length();
        
        for(int j = 0; j < len; j += 8){
            int ones_count = 0;
            
            for(int k = 0; k < 7; ++k){
                if(str[j + k] == '1'){
                    ones_count++;
                }
            }
            
            char transmitted_parity = str[j + 7];
            
            char expected_parity;
            if (ones_count % 2 != 0) {
                expected_parity = '1';
            } else {
                expected_parity = '0';
            }

            if(transmitted_parity != expected_parity){
                error_count++;
            }
        }
        
        cout << error_count << '\n';
    }
    
    return 0;
}