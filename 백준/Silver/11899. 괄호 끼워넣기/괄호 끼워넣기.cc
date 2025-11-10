#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solve(){
    string str;
    cin >> str;
    stack<char> st;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            st.push(str[i]);
        else{
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else
                st.push(str[i]);
        }
    }
    
    cout << st.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}