#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define DATA pair<int, int>

using namespace std;


int n;

vector<DATA> animals;

bool cmp(const DATA &a, const DATA &b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;
    }
}

bool cmp_lis(const DATA &a, int val){
    return a.first < val;
}

void init(){
    cin >> n;
    int a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        animals.push_back({b, c});
    }
    sort(animals.begin(), animals.end(), cmp);
    animals.erase(unique(animals.begin(), animals.end()), animals.end());
}

void solve(){
    vector<int> pos;
    vector<int> lis;
    pos.resize(n);
    int max_size = 0;
    // for(int i = 0; i < animals.size(); i++){
    //     cout << animals[i].l << ' ' << animals[i].r << ' ' << animals[i].num << endl;
    // }
    
    for(int i = 0; i < n; i++){
        int val = animals[i].second;
        auto it = upper_bound(lis.begin(), lis.end(), -1 * val);
        int idx = it - lis.begin();
        
        if(it == lis.end()){
            lis.push_back(-1 * val);
        }
        else{
            *it = -1 * val;
        }
        pos[i] = idx;
        //cout << lis.size() << ' ' << val << endl;
    }
    
    cout << lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}