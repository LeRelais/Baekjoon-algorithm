#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 1. 시각(HHMM)을 분 단위로 변환 (HH*60 + MM)
int time_to_minutes(int time_hhmm) {
    int hour = time_hhmm / 100;
    int minute = time_hhmm % 100;
    return hour * 60 + minute;
}

// 2. 분 단위 시간에 10분을 더하고 다시 시각(HHMM)으로 변환 (최대 허용 시각 계산)
int add_10_minutes(int time_hhmm) {
    int total_minutes = time_to_minutes(time_hhmm) + 10;
    int new_hour = total_minutes / 60;
    int new_minute = total_minutes % 60;
    return new_hour * 100 + new_minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int honest_employees_count = 0;
    int num_employees = schedules.size();

    // 요일 인덱스: 1(월) ~ 7(일)

    for (int x = 0; x < num_employees; x++) {
        int start_t = schedules[x];
        int allowed_t = add_10_minutes(start_t); // 출근 인정 시각 (HHMM)

        int honest_day_count = 0; // 평일 5일 중 성실 출근 횟수

        for (int i = 0; i < 7; i++) {
            // 이벤트 시작일(startday)로부터 i일째의 요일 (1 ~ 7)
            // (startday - 1 + i) % 7 + 1
            int day_of_week = ((startday - 1) + i) % 7 + 1;
            
            // timelogs[x][i]는 이벤트 j+1일차 (i일차)에 출근한 시각입니다.
            int arrive_t = timelogs[x][i]; 
            
            // 1. 주말 체크: 토요일(6), 일요일(7)은 무시
            if (day_of_week == 6 || day_of_week == 7) {
                continue;
            }
            
            // 2. 성실 조건 체크: 출근 시간이 허용 시각(start_t + 10분)보다 늦지 않은 경우
            if (arrive_t <= allowed_t) {
                honest_day_count++;
            } else {
                // 한 번이라도 지각하면 (평일 5일 중) 즉시 불성실 확정
                // 이 방법 대신, 루프가 끝난 후 '5'인지 확인하는 현재 방식이 더 간단합니다.
            }
        }

        // 3. 최종 판단: 평일 5일 모두 성실하게 출근했는지 확인
        if (honest_day_count == 5) {
            honest_employees_count++;
        }
    }

    return honest_employees_count;
}