#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // d_remain: 현재까지 처리해야 할 배달량
    // p_remain: 현재까지 처리해야 할 수거량
    int d_remain = 0;
    int p_remain = 0;

    // 가장 먼 집 (n-1)부터 물류창고 (0)까지 역순으로 순회
    for (int i = n - 1; i >= 0; --i) {
        // 현재 집 i에서 처리할 양을 잔여량에 추가
        d_remain += deliveries[i];
        p_remain += pickups[i];
        
        // i번째 집에 배달/수거할 것이 아무것도 없으면 패스 (i가 가장 먼 집이 아님)
        if (d_remain == 0 && p_remain == 0) continue;

        // 이번 왕복으로 모든 d_remain과 p_remain을 처리하는 데 필요한 횟수 계산
        // d_remain과 p_remain이 모두 0보다 커질 때까지 왕복을 반복
        int trips = 0;
        
        // d_remain과 p_remain 중 하나라도 남은 경우 (처리할 것이 남아있는 경우)
        while (d_remain > 0 || p_remain > 0) {
            // 왕복 횟수 증가
            trips++;
            
            // 배달: cap만큼 배달했다고 가정하고 d_remain에서 cap만큼 차감
            d_remain -= cap;
            
            // 수거: cap만큼 수거했다고 가정하고 p_remain에서 cap만큼 차감
            p_remain -= cap;
        }

        // 현재 왕복 횟수 * 가장 먼 집 (i+1)까지의 왕복 거리 (2 * (i+1))를 누적
        // (i+1은 집 번호이자 물류창고로부터의 거리)
        answer += (long long)trips * 2 * (i + 1);
    }

    return answer;
}