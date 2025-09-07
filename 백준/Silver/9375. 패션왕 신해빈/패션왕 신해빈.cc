#include <iostream>
#include <map>
#include <string>

using namespace std;

void solve(){
    map<string, int> clothes;
    int n;
    
    cin >> n;
    
    string cloth, category;
    
    for(int i = 0; i < n; i++){
        cin >> cloth >> category;
        clothes[category]++;
    }
    
    int res = 1;
    for(auto i = clothes.begin(); i != clothes.end(); i++){
        res *= (i->second + 1);
    }
    
    cout << res - 1 << '\n';
}

int main() {
    
    int t;
    cin>> t;
    
    while(t--){
        solve();
    }
}