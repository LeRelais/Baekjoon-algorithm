#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b;
vector<int> v;

int main() {
    cin >> a >> b; 
    
    int tmp;
    for(int i = 0; i < a; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int l_pointer = 0, r_pointer = 0;
    
    int sum = v[0], len = 1;
    int res = 987654321;
    while(r_pointer >= l_pointer && r_pointer < a){
        if(sum >= b){
            res = min(res, len);
        }
        
        if(sum < b){
            r_pointer++;
            sum += v[r_pointer];
            len++;
        }
        else{
            sum -= v[l_pointer];
            l_pointer++;
            len--;
        }
    }
    
    if(res != 987654321)
        cout  << res;
    else
        cout << 0;
}