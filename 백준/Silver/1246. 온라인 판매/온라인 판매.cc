#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> customers;

int main() {
    cin >> n >> m;
    int c;
    for(int i = 0; i < m; i++){
        cin >> c;
        customers.push_back(c);
    }    
    
    sort(customers.begin(), customers.end());
    long long res = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int num = min(n, m-i);
        int price = customers[i];
        
        if(res < (long long)num*price){
            cnt = price;
            res = (long long)num*price;
        }
    }
    
    cout << cnt << ' ' << res;
    return 0;
}