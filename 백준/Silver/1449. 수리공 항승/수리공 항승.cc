#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, l, tmp;
    
    cin >> n >> l;
    queue<int> q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        q.push(v[i]);
    }
    
    int res = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        res += 1;
        while(q.front() <= x + l -1 && !q.empty()){
            q.pop();
        }
    }
    
    cout << res;
}