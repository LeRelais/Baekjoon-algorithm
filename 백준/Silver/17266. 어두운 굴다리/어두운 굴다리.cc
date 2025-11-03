#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos;
int n, m, x;

bool check(int h){
    if(pos[0] - h > 0)
        return false;
    
    for(int i = 1; i < pos.size()-1; i++){
        int dist = pos[i] - pos[i-1];
        if(dist - 2*h > 0)
            return false;
    }
    
    if(pos[pos.size()-1] + h < n)
        return false;
        
    return true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> x;
        pos.push_back(x);
    }
    
    int l = 1, r = n;
    int res = 987654321;
    while(l <= r){
        int mid = (l + r) / 2;
        
        if(check(mid)){
            r = mid - 1;
            res = min(mid, res);
        }
        else{
            l = mid + 1;
        }
    }
    
    cout << res;
    return 0;
}