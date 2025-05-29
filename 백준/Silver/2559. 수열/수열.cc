#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, max_sum, cur_sum;
vector<int> temperatures;
int main() {
    cin >> n >> k;
    
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        temperatures.push_back(tmp);
    }
    
    for(int i = 0; i < k; i++){
        cur_sum += temperatures[i];
    }
    
    max_sum = cur_sum;
    
    for(int i = k; i < n; i++){
        cur_sum = cur_sum - temperatures[i-k] + temperatures[i];
        max_sum = max(max_sum, cur_sum);
    }
    
    cout << max_sum;
    return 0;
}