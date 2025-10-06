#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// 날짜를 2000.01.01 기준의 총 일수로 변환 (모든 달은 28일 가정)
int dateToDays(int y, int m, int d) {
    return (y * 12 * 28) + (m * 28) + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> term_map; // 약관 종류: 월

    // 1. terms 맵 생성 (약관 기간을 월 단위로 저장)
    for(const string& t : terms){
        term_map[t[0]] = stoi(t.substr(2));
    }

    // 2. 오늘 날짜를 총 일수로 변환
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));
    
    // TotalDays: 2000년 1월 1일 기준의 총 일수
    // 2000.01.01의 일수를 0으로 가정하면 (Y-2000)*12*28 + (M-1)*28 + (D-1)이 됩니다.
    // 하지만, D_{\text{expire}} \le D_{\text{today}}의 비교만 정확하면 되므로 단순 계산식을 사용합니다.
    int today_total_days = dateToDays(today_year, today_month, today_day);

    // 3. privacies 처리
    for(int i = 0; i < privacies.size(); i++){
        const string& p = privacies[i];
        
        // 정보 수집일
        int collect_year = stoi(p.substr(0, 4));
        int collect_month = stoi(p.substr(5, 2));
        int collect_day = stoi(p.substr(8, 2));
        char term_type = p.back(); // 약관 종류 문자

        // 수집일을 총 일수로 변환
        int collect_total_days = dateToDays(collect_year, collect_month, collect_day);
        
        // 약관 기간을 일수로 변환 및 파기 기한 계산
        int term_months = term_map[term_type];
        int term_days = term_months * 28;
        
        // 파기 기한일: 수집일 + 약관 일수
        int expire_total_days = collect_total_days + term_days - 1; 

        // 파기 조건 확인: 파기 기한일 < 오늘 날짜
        // 즉, 파기 기한일(inclusive)을 넘긴 시점(오늘)은 파기 대상입니다.
        if (expire_total_days < today_total_days) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}