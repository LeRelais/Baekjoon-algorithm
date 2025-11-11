#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v = vector<int>(n);
    deque<int> dq;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int num = 1;
    for(int i = n-1; i >= 0; i--){
        if(v[i] == 1){
            dq.push_front(num);
        }
        else if(v[i] == 2){
            if(dq.size() == 1){
                dq.push_back(num);
            }
            else{
                int tmp = dq.front();
                dq.pop_front();
                dq.push_front(num);
                dq.push_front(tmp);
            }
        }
        else{
            dq.push_back(num);
        }
        num++;
    }
    
    while(!dq.empty()){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    return 0;
}