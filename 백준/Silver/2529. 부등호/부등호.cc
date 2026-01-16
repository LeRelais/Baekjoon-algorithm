#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<char> signs;
int used[10], n;
set<string> s;

void make_num(int nth, string str){
    if(nth == n+1){
        s.insert(str);
        return;
    }
    
    for(int i = 0; i < 10; i++){
        if(signs[nth-1] == '<'){
            if((str[nth-1]-'0' < i) && !used[i]){
                used[i] = 1;
                string tmp = "";
                tmp += to_string(i);
                make_num(nth+1, str+tmp);
                used[i] = 0;
            }
        }
        
        if(signs[nth-1] == '>'){
            if((str[nth-1]-'0' > i) && !used[i]){
                used[i] = 1;
                string tmp = "";
                tmp += to_string(i);
                make_num(nth+1, str+tmp);
                used[i] = 0;
            }
        }        
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        signs.push_back(c);
    }
    
    for(int i = 0; i < 10; i++){
        if(!used[i]){
            used[i] = 1;
            make_num(1, to_string(i));
            used[i] = 0;
        }
    }
    cout << *s.rbegin() << '\n' << *s.begin();
    return 0;
}