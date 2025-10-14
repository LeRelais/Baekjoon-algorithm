#include <iostream>
#include <vector>
using namespace std;

int t;

void init(){
    cin >> t;
}

void solve(){
    for(int x = 1; x <= t; x++){
        vector<int> stu(20, 987654321);
       
        int cur_size = 0;
        long long res = 0;
        int cnt;
        cin >> cnt;
        for(int i = 0; i < 20; i++){
            int tmp;
            cin >> tmp;
            int insert_idx = cur_size;
            
            for(int j = 0; j < cur_size; j++){
                if(stu[j] > tmp){
                    insert_idx = j;
                    break;
                }
            }
            
            res += (cur_size - insert_idx);
            
            for(int j = cur_size; j > insert_idx; j--){
                stu[j] = stu[j-1];
            }
            stu[insert_idx] = tmp;
            cur_size++;
            
        }

        cout << x << " " << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}