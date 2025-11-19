#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    while(n--){
        cin >> str;
        for(int i = 0; i < str.length(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                cout << (char)(str[i] - 'A' + 'a');
            }
            else
                cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}