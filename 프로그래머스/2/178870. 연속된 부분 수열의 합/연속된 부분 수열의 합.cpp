#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    
    // 투 포인터 초기화
    int L = 0;
    int R = 0;
    long long current_sum = 0; // 합 k가 최대 10억이므로 long long 사용
    
    // 최소 길이 및 최적의 시작/끝 인덱스 초기화
    int min_len = INT_MAX;
    vector<int> result = {};

    // R 포인터는 수열의 끝까지 이동
    while (R < n) {
        // 1. R을 이동시켜 current_sum 증가
        current_sum += sequence[R];

        // 2. current_sum > k 일 때, L을 이동시켜 current_sum 감소
        // R은 이미 증가했으므로, L을 R보다 뒤로 이동시킬 수는 없음 (L <= R 보장)
        while (current_sum > k) {
            current_sum -= sequence[L];
            L++;
        }

        // 3. current_sum == k 일 때, 최적의 답 갱신
        if (current_sum == k) {
            int current_len = R - L + 1;
            
            // 최적의 답 갱신 조건:
            // 1) 현재 길이가 기존 최소 길이보다 짧으면 무조건 갱신
            // 2) 길이가 같으면, 시작 인덱스가 더 작은 것(L이 작은 것)을 선택해야 함.
            //    -> **주의**: 투 포인터는 L을 앞에서부터 시작하므로,
            //       L이 증가하기 전에 먼저 발견된 것이 항상 '앞쪽'에 있습니다.
            //       따라서, 길이가 같으면 갱신하지 않고 현재 result를 유지하면 됩니다.
            //       (L이 같으면 R도 같고, L이 증가하면 다음 부분 수열은 더 뒤에 시작함)
            
            if (current_len < min_len) {
                min_len = current_len;
                result = {L, R};
            } 
            // 길이가 같을 때, 이미 찾은 result가 L이 더 작거나 같으므로 갱신하지 않음.
            
            // k를 만족했으므로 L을 한 칸 이동시켜 다음 부분 수열 탐색 (필수)
            current_sum -= sequence[L];
            L++;
        }
        
        // 다음 칸으로 R 이동
        R++;
    }

    return result;
}