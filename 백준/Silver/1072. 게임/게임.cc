#include <iostream>
#include <algorithm>

using namespace std;

// 승률 Z를 계산하는 함수: Z = floor((Y * 100) / X)
// X, Y가 최대 10억이므로, Y * 100은 1000억으로 long long 사용
long long calculate_z(long long x, long long y) {
    if (x == 0) return 0; // x가 0일 경우 예외 처리 (문제 조건 상 x >= 1)
    return (y * 100) / x;
}

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;

    // 1. 초기 승률 Z 계산
    long long current_Z = calculate_z(X, Y);

    // 2. 초기 승률이 99% 이상일 경우 (Z가 100이 될 수 없음)
    // 99%인 경우, X가 아무리 커져도 Z는 100이 될 수 없으므로 변하지 않음
    if (current_Z >= 99) {
        cout << -1 << "\n";
        return;
    }

    // 3. 이분 탐색 범위 설정
    // 최소 1판부터, 최대 20억판까지 탐색 (X의 최대 범위에 맞춰 충분히 크게 잡음)
    // 2 * 10^9를 잡아도 괜찮지만, X의 범위가 10억이므로 10억 * 2로 충분
    long long L = 1;
    long long R = 2000000000; 
    long long result = -1; // 답이 없을 경우 -1 유지

    while (L <= R) {
        long long mid = L + (R - L) / 2; // mid: 추가할 게임 횟수 (M)

        // M번 게임 후의 새로운 승률 Z' 계산
        long long new_X = X + mid;
        long long new_Y = Y + mid;
        long long new_Z = calculate_z(new_X, new_Y);

        // 4. 결정 문제: 새로운 승률 Z'이 원래 Z보다 커졌는가? (Z' > Z)
        if (new_Z > current_Z) {
            // 성공: mid가 가능한 정답임. 최소값을 찾아야 하므로 기록 후 R을 줄임.
            result = mid;
            R = mid - 1;
        } else {
            // 실패: mid가 너무 작음. Z가 변하지 않음. L을 늘려 게임 횟수를 늘림.
            L = mid + 1;
        }
    }

    // 5. 결과 출력 (result가 -1이면 변하지 않는 경우, 아니면 최소 게임 횟수)
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 문제의 입력이 T 테스트 케이스 형태가 아닌, 단일 입력이므로 main 함수를 조정합니다.
    solve();
    
    return 0;
}