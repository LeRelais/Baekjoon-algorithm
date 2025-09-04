#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int seven_seg[10] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
int n, k, p, x, res;

int find_diff(int a, int b){
int xor_val = seven_seg[a] ^ seven_seg[b];
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if ((xor_val >> i) & 1) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k >> p >> x;
    
    for(int i = 1; i <= n; i++){
        if(i == x) continue;
        
        int tmp_i = i, tmp_x = x, diff_cnt = 0;
        
        for(int j = 0; j < k; j++){
            int digit_i = tmp_i % 10;
            int digit_x = tmp_x % 10;
            
            diff_cnt += find_diff(digit_i, digit_x);
            
            tmp_i /= 10;
            tmp_x /= 10;
        }
        
        if(diff_cnt <= p)
            res++;
    }
    
    cout << res;
}