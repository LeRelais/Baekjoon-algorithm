#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    int cnt = 1;
    while(true){
        cin >> str;
        
        if(str[0] == '-'){
            break;
        }
        
        stack<char> st;
        
        for(int i = 0; i < str.length(); i++){
            if(st.empty()){
                st.push(str[i]);
            }        
            else{
                if(str[i] == '}'){
                    if(st.top() == '{')
                        st.pop();
                    else
                        st.push(str[i]);
                }
                else{
                    st.push({str[i]});
                }
            }
        }
        int res = 0;
        
        while(!st.empty()){
            char b = st.top();
            st.pop();
            char a = st.top();
            st.pop();
            
            if(a == b){
                res += 1;
            }
            else{
                res += 2;
            }
        }
    
        cout << cnt << ". " << res << '\n';
        cnt++;
    }
    return 0;
}