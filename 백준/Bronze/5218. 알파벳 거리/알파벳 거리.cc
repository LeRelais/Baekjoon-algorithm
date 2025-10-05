#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string str1, str2;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2;
        cout << "Distances: ";
        for(int j = 0; j < str1.length(); j++){
            cout << (str2[j] - str1[j] + 26) % 26 << ' ';
        }
        cout << '\n';
    }
}