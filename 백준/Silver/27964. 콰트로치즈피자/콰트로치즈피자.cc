#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    string topping;
    map<string, int> toppings;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> topping;
        
        if(topping.find("Cheese",topping.length()-6)!=string::npos){
            toppings.insert(pair<string, int>(topping, 1));
        }
    }
    
    if(toppings.size() >= 4){
        cout << "yummy";
    }
    else
        cout << "sad";
        
    return 0;
}