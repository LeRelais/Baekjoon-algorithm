#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input, tmp;
    int t, cnt = 0, res = 0;
    
    cin >> t;
    
    while(t--){
        cin >> input;
        tmp = "";
        cnt = 0;
        
        for(int i = 0; i < input.length(); i++){
            if(input[i] == 'f'){
                tmp = input.substr(i, 3);
                
                if(tmp == "for")
                    cnt++;
            }
            
            if(input[i] == 'w'){
                tmp = input.substr(i, 5);
                
                if(tmp == "while")
                    cnt++;
            }
        }
        
        res = max(res, cnt);
    }
    
    cout << res;
    return 0;
}