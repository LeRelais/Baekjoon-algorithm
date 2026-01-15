#include <iostream>
#include <vector>

using namespace std;

int used[51], n, k, target = 500, res;
vector<int> kits;

void find_combs(int nth, int weight){
    if(nth == n){
        res++;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!used[i] && weight-k+kits[i] >= 500){
            used[i] = 1;
            find_combs(nth+1, weight-k+kits[i]);
            used[i] = 0;
        }
    }
}

int main() {
    
    cin >> n >> k;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        kits.push_back(tmp);
    }
    
    for(int i = 0; i < n; i++){
        if(!used[i] && target-k+kits[i] >= 500){
            used[i] = 1;
            find_combs(1, target-k+kits[i]);
            used[i] = 0;
        }
    }
    
    cout << res;
    return 0;
}