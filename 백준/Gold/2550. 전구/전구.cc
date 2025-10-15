#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct _line{
    int a;
    int b;
    int num;
}LINE;
vector<LINE> lines;

bool cmp(const LINE &a, const LINE &b){
    return a.a < b.a;
}

void init(){
    vector<int> from, to;
    cin >> n;
    from.resize(n+1);
    to.resize(n+1);
    int tmp;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        from[tmp] = i+1;
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        to[tmp] = i+1;
    }
    
    for(int i = 1; i <= n; i++){
        lines.push_back({from[i], to[i], i});
    }
    
    sort(lines.begin(), lines.end(), cmp);
}

void solve(){
    vector<int> lis;
    vector<int> pos(n+1);
    for(int i = 0; i < n; i++){
        int val = lines[i].b;
        auto it = lower_bound(lis.begin(), lis.end(), val);
        int p = it - lis.begin();
        if(it == lis.end()){
            lis.push_back(val);
        }
        else
            *it = val;
        pos[i] = p;
    }
    
    cout << lis.size() << '\n';
    vector<int> res_v;
    int len = lis.size() - 1;
    for(int i = n-1; i >= 0; i--){
        if(pos[i] == len){
            len--;
            res_v.push_back(lines[i].num);
        }
        if(len < 0)
            break;
    }
    
    sort(res_v.begin(), res_v.end());
    for(int i = 0; i < res_v.size(); i++){
        cout << res_v[i] << ' ';
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}