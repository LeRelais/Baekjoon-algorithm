#include <iostream>
#include <map>
using namespace std;

map<string, int> trace;

void solve(){
    int q, res = 0;
    cin >> q;
    string name;
    char info;
    while(q--){
        cin >> name >> info;
        
        if(info == '+'){
            trace[name]++;
        }
        else{
            if(trace[name] == 0){
                res++;
            }
            else{
                trace[name]--;
            }
        }
    }
    
    for(const auto &i : trace){
        res += i.second;
    }
    
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}