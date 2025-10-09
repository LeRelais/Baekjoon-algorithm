#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int flag = 0, l_cnt = 0, r_cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            while(str[i] != ')'){
                i++;
            }
            flag = 1;
        }
        else{
            if(str[i] == '@'){
                if(!flag)
                    l_cnt++;
                else
                    r_cnt++;
            }
        }
    }
    
    cout << l_cnt << ' ' << r_cnt;
    return 0;
}