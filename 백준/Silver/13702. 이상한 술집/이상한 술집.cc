#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// drinks는 용량이 크므로 long long으로 변경
vector<long long> drinks; 
int n;
long long k; // K도 최대 100만이지만, 통일성을 위해 long long 사용 가능

void init(){
    cin >> n >> k;
    drinks.resize(n);
    
    for(int i = 0; i < n; i++){
        // 입력 받을 때도 long long으로 받습니다.
        cin >> drinks[i]; 
    }
}

// check 함수의 인자 V도 최대 2^31 - 1이므로 long long 사용
bool check(long long v){
    if (v == 0) return true; // 분배 용량이 0이면 항상 성공 (최대 용량을 찾아야 하므로 L=1로 시작하면 생략 가능)
    
    // cnt는 최대 K 근처에서 멈추므로 int로 충분하지만,
    // K가 long long이므로 cnt도 long long으로 맞추는 것이 안전
    long long cnt = 0;
    
    for(long long drink : drinks){
        cnt += drink / v;
        
        if(cnt >= k)
            return true;
    }
    return cnt >= k;
}

void solve(){
    long long max_v = 0; // max_v는 long long
    for(int i = 0; i < n; i++){
        max_v = max(max_v, drinks[i]);
    }
    
    // L, R, res 모두 long long으로 선언하여 오버플로우 방지
    long long l = 1, r = max_v;
    long long res = 0; // 최소한 0ml는 가능하므로 0으로 초기화
    
    while(l <= r){
        // mid 계산 시 오버플로우 방지
        long long mid = l + (r - l) / 2; 
        
        if(check(mid)){
            res = mid;
            l = mid + 1; // 가능한 최대 용량을 찾기 위해 L 증가
        }
        else
            r = mid - 1; // 용량을 줄여야 함
    }
    
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}