#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> ingredients;

int main() {
    int n;
    string tmp;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        ingredients[tmp]++;
    }
    
    for(int i = 0; i < n-1; i++){
        cin >> tmp;
        ingredients[tmp]++;
    }
    
    for(auto it = ingredients.begin(); it != ingredients.end(); it++){
        if(it->second != 2){
            cout << it->first;
            break;
        }
    }
    return 0;
}