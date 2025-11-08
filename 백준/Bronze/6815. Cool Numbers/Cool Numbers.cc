#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    // a와 b는 최대 10^8이므로 int로 충분합니다.
    long long a, b;
    
    // 입력 처리
    if (!(cin >> a >> b)) return;

    int cool_count = 0;
    
    // 10^8의 6제곱근은 약 21.54이므로, z는 1부터 21까지만 탐색하면 됩니다.
    // 21^6 = 85,766,121 (범위 내)
    // 22^6 = 113,988,724 (범위 초과)
    const int MAX_Z = 21; 

    // z^6을 계산할 때 long long 범위를 벗어나지 않도록 주의합니다.
    // 여기서는 10^8이 최대이므로 long long z_power_6을 사용하면 안전합니다.
    
    for (long long z = 1; z <= MAX_Z; ++z) {
        // z^6 계산
        // pow(z, 6)은 double을 반환하므로 정확하지 않을 수 있습니다.
        // 직접 z * z * z * z * z * z를 사용하여 정확한 정수 계산을 수행합니다.
        long long z_power_6 = z * z * z;
        z_power_6 = z_power_6 * z_power_6;
        
        // z_power_6이 b를 초과하면 더 이상 탐색할 필요가 없습니다.
        if (z_power_6 > b) {
            break;
        }

        // z_power_6이 [a, b] 범위 내에 있는지 확인
        if (z_power_6 >= a && z_power_6 <= b) {
            cool_count++;
        }
    }

    cout << cool_count << endl;
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}