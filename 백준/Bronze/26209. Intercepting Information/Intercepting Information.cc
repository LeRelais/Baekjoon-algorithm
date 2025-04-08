#include <iostream>

using namespace std;

int main() {
    int n;
    
    for(int i = 0; i < 8; i++){
        cin >> n;
        if(n == 9){
            cout << "F";
            return 0;
        }
    }
    
    cout << "S";
    return 0;
}