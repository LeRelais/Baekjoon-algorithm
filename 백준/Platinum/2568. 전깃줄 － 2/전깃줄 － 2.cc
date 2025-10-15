#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct _line{
    int a;
    int b;
} LINE;
vector<LINE> lines;

bool cmp(const LINE &a, const LINE &b){
    return a.a < b.a;
}

void init(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end(), cmp);
}

void solve(){
    vector<int> lis, p;
    int max_len = 0, idx;
    p.resize(lines.size());
    for(int i = 0; i < lines.size(); i++){
        int val = lines[i].b;
        auto it = lower_bound(lis.begin(), lis.end(), val);
        int lis_len = it - lis.begin();
        
        if(it == lis.end()){
            lis.push_back(val);
        }
        else{
            *it = val;
        }
        p[i] = lis_len;
        if(max_len < lis_len + 1){
            max_len = lis_len + 1;
            idx = i;
        }
    }
    
    vector<int> used(lines.size(), 0);
    int start_len = max_len-1;
    for(int i = lines.size()-1; i >= 0; i--){
        if(p[i] == start_len){
            used[i] = 1;
            start_len--;
        }
        if(start_len < 0)
            break;
    }
    
    cout << lines.size() - lis.size() << '\n';
    for(int i = 0; i < lines.size(); i++){
        if(!used[i]){
            cout << lines[i].a << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}