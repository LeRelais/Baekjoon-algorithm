#include <iostream>
#include <stack>
#include <string>
#include <deque>

using namespace std;

int main() {
    string s;
    string f;
    
    cin >> s;
    cin >> f;
    
    string t ="";
    
    for(int i = 0; i < s.length(); i++){
        t += s[i];
        int flag = 1;
        int tmp = 0;
        //cout << t << endl;
        if(t.length() >= f.length()){
            for(int j = 0; j < f.length(); j++){
                if(t[t.length()-f.length()+j] != f[j])
                {
                    flag = 0;
                    break;
                }
            }
            
            if(flag){
                t.erase(t.end()-f.length(), t.end());
            }
        }
    }
    
    if(!t.empty())
        cout << t;
    else
        cout << "FRULA";
    
    return 0;
}