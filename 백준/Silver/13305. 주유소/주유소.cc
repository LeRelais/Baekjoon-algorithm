#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dist, price;

void init(){
    cin >> n;
    int tmp;
    for(int i = 0; i < n-1; i++){
        cin >> tmp;
        dist.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        price.push_back(tmp);
    }
}

void solve(){
    long long res = 0;
    
    for(int i = 0; i < n-1; i++){
        int idx = i;
        long long sum = dist[i];
        while(i+1 < n-1 && price[idx] < price[i+1]){
            sum += dist[i+1];
            i++;
        }
        //cout << i << ' ' << idx << ' ' << sum << endl;
        res += price[idx] * sum;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}