#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 대량의 입출력을 위해 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string S;
    cin >> N >> M >> S;

    int ans = 0;
    for (int i = 0; i < M - 2; i++) {
        // "IOI" 패턴의 시작점 발견
        if (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I') {
            int count = 0;
            // "OI"가 몇 번 연속되는지 확인
            while (S[i + 1] == 'O' && S[i + 2] == 'I') {
                count++;
                // "OI"가 N번 반복되었다면 PN을 하나 찾은 것
                if (count >= N) {
                    ans++;
                }
                i += 2; // "OI" 단위로 점프
                if (i >= M - 2) break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}