#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> s;
int n, p, l, m;
int problems[100001];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> p >> l;
        s.insert({l, p});
        problems[p] = l;
    }
    
    cin >> m;
    string cmd;
    int rc;
    
    for(int i = 0; i < m; i++){
        cin >> cmd;
        
        if(cmd == "add"){
            cin >> p >> l;
            s.insert({l, p});
            problems[p] = l;
        }
        else if(cmd == "recommend"){
            cin >> rc;
            
            if(rc == 1){
                cout << s.rbegin()->second << '\n';
            }
            else
                cout << s.begin()->second << '\n';
        }
        else{
            cin >> p;
            
            s.erase({problems[p], p});
        }
    }
    return 0;
}