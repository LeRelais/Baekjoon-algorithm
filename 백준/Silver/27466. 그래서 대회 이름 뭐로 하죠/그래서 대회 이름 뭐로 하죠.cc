#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int k;
    string tmp = "";
    for(int i = str.length()-1; i >= 0; i--){
        if(str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
            k = i;
            tmp += str[i];
            break;
        }
    }
    
    int flag = 0;
    for(int i = k-1; i >= 0; i--){
        if(str[i] == 'A')
        {
            k = i;
            tmp += str[i];
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        cout << "NO";
        return 0;
    }
    
    flag = 0;
    for(int i = k-1; i >= 0; i--){
        if(str[i] == 'A')
        {
            k = i;
            tmp += str[i];
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        cout << "NO";
        return 0;
    }
    
    for(int i = k-1; i >= 0; i--){
            tmp += str[i];
            if(tmp.length() == m)
                break;
    }
    reverse(tmp.begin(), tmp.end());
    if(tmp.length() < m){
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << tmp;
    return 0;
}