#include <iostream>
#include <deque>

using namespace std;

int n, cmd, num;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        cin >> cmd;
        
        if(cmd == 1){
            cin >> num;
            dq.push_front(num);
        }
        else if(cmd == 2){
            cin >> num;
            dq.push_back(num);
        }
        else if(cmd == 3){
            if(dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == 4){
            if(dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == 5){
            cout << dq.size() << '\n';
        }
        else if (cmd == 6){
            if(dq.empty()){
                cout << "1\n";
            }
            else
                cout << "0\n";
        }
        else if(cmd == 7){
             if(dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.front() << '\n';
            }
        }
        else if(cmd == 8){
             if(dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.back() << '\n';
            }
        }
        else
            continue;
    }
    return 0;
}