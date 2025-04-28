#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st; int n, cmd, num;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> cmd;
        
        if(cmd == 1){
            cin >> num;
            st.push(num);
        }
        else if(cmd == 2){
            if(!st.empty()){
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if(cmd == 3){
            cout << st.size() << '\n';
        }
        else if(cmd == 4){
            if(st.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else{
            if(!st.empty()){
                cout << st.top() << '\n';
            }
            else
                cout << -1 << '\n';
        }
    }
    return 0;
}