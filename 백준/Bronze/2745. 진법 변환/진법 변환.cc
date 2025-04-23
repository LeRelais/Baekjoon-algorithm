#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string s;
    int b;
    long long res = 0;
    cin >> s >> b;
    
    int digit = 0;
    
    for(int i = s.length()-1; i >= 0; i--){
        int tmp;
        if(s[i] >= 'A' && s[i] <= 'Z'){
            tmp = s[i] - 'A' + 10;
        }
        else{
            tmp = s[i] - '0';
        }
        
        res += pow(b, digit) * tmp;
        digit += 1; 
    }  
    
    cout << res;
    return 0;
}