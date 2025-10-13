#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    string tmp, res;
    cin >> tmp;
    res = tmp;
    t--;
    while(t--){
        cin >> tmp;
        for(int i = 0; i < tmp.length(); i++){
            if(res[i] != tmp[i] && res[i] != '?')
                res[i] = '?';
        }
    }
    
    cout << res;
    return 0;
}