#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int dp[501][501]은 main 함수 밖에서 전역 변수로 선언할 경우 자동으로 0으로 초기화됩니다.
int dp[501][501];
vector<pair<int, int>> v;
int n, r, c;

void init() {
    cin >> n;
    v.resize(n); // 벡터 크기를 n으로 미리 조정
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    // len은 곱할 행렬의 개수를 나타냅니다. 2부터 n까지 증가
    for (int len = 2; len <= n; len++) {
        // i는 행렬 그룹의 시작 인덱스 (0부터 n-len까지)
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // j는 행렬 그룹의 끝 인덱스
            
            dp[i][j] = 2147483647; // int의 최댓값으로 초기화
            
            // 분할점 k를 순회
            for (int k = i; k < j; k++) {
                // (i부터 k까지) + (k+1부터 j까지)의 곱셈 횟수
                // + 두 그룹의 결과를 곱하는 횟수
                long long cost = (long long)dp[i][k] + dp[k + 1][j] + 
                                 (long long)v[i].first * v[k].second * v[j].second;
                
                // 최솟값 업데이트
                dp[i][j] = min((long long)dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;
}