#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> pos;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> c;
    
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pos.push_back(tmp);
    }
    
    sort(pos.begin(), pos.end());
    
    long long low = 1, high = pos[pos.size()-1]-pos[0];
    long long res = 0;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long cnt = 1;
        int cur = pos[0];
        for(int i = 1; i < pos.size(); i++){
            if((long long)pos[i] - cur >= mid){
                cur = pos[i];
                cnt++;
            }
            if(cnt >= c)
                break;
        }
        
        if(cnt >= c){
            res = max(res, mid);
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    cout << res;
    return 0;
}