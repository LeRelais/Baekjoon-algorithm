#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<pair<int, int>> dq;
    vector<int> v;
    int n;
    cin >> n;
    int tmp;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        dq.push_back({i+1, tmp});
    }
    
    int cur = 0;
    while(!dq.empty()){
        int idx = dq.front().first;
        int move = dq.front().second;
        dq.pop_front();
        v.push_back(idx);
        
        if(dq.empty())
            break;
        
        if(move > 0){
            int cnt = (move-1) % dq.size();
            
            for(int i = 0; i < cnt; i++){
                pair<int, int> tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
        }
        else{
            int cnt = abs(move) % dq.size();
            for(int i = 0; i < cnt; i++){
                pair<int, int> tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    return 0;
}