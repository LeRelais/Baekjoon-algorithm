#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int h = 0, cur_stress = 0, total_work = 0;
    
    while(h < 24){
        if(cur_stress + a <= m){
            total_work += b;
            cur_stress += a;
        }
        else{
            cur_stress -= c;
            if(cur_stress < 0)
                cur_stress = 0;
        }
        h++;
    }
    
    cout << total_work;
}