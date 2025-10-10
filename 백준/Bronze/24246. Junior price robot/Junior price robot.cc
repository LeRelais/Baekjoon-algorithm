#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    
    int a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    
    int tmp = v[0];
    
    int flag = 1, cnt = 1;
    
    for(int i = 1; i < n; i++){
        if(v[i] <= tmp){
            flag = 0;
            break;
        }
        cnt++;
    }
    
    if(flag){
        cout << "infinity";
    }
    else
        cout << cnt;
    
    return 0;
}