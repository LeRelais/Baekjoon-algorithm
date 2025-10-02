#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, res="";
    cin >> str;
    
    if(str[0] >= 'A' && str[0] <= 'Z'){
        cout << "Error!";
        return 0;
    }
    
    if(str[0] == '_' || str[str.length()-1] == '_'){
        cout << "Error!";
        return 0;
    }
    
    if (str.find("__") != string::npos) {
        cout << "Error!" << endl;
        return 0;
    }
    
    bool underscore = false;
    bool uppercase = false;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '_')
            underscore = true;
        if(str[i] >= 'A' && str[i] <= 'Z')
            uppercase = true;
    }
    
    if(uppercase && underscore){
        cout << "Error!";
        return 0;
    }
    
    if(!uppercase && !underscore){
        cout << str;
        return 0;
    }
    if(underscore){
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '_'){
                res += (str[i+1] - 'a' + 'A');
                i += 1;
            }
            else
                res += str[i];
        }
    }
    if(uppercase){
         for(int i = 0; i < str.length(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                res += '_';
                res += (str[i] - 'A' + 'a');
            }
            else
                res += str[i];
        }
    }
    
    cout << res;
}