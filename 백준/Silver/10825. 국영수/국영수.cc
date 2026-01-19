#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _data{
    string name;
    int lan;
    int eng;
    int math;
}DATA;

bool cmp(const DATA &a, const DATA &b){
    if (a.lan != b.lan) {
        return a.lan > b.lan;
    }
    if (a.eng != b.eng) {
        return a.eng < b.eng;
    }
    if (a.math != b.math) {
        return a.math > b.math;
    }
    return a.name < b.name;
}

vector<DATA> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    string name;
    int l, e, m;
    for(int i = 0; i < n; i++){
        cin >> name >> l >> e >> m;
        v.push_back({name, l, e, m});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i].name << '\n';
    }
    return 0;
}