#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 비밀 코드로 가능한 조합의 개수를 계산하는 재귀 함수
// n: 최대 숫자, q: 시도 목록, ans: 시스템 응답 목록
// start_num: 이번 레벨에서 숫자를 뽑기 시작할 숫자
// current_pass: 현재까지 뽑힌 비밀 코드 후보 (항상 오름차순으로 정렬됨)
// result_count: 조건 만족하는 조합의 총 개수 (참조로 전달)
void generate_combination(const int n, 
                          const vector<vector<int>>& q, 
                          const vector<int>& ans,
                          int start_num, 
                          vector<int>& current_pass, 
                          int& result_count) {
    
    // 1. 종료 조건: 5개의 숫자를 모두 뽑았을 때
    if (current_pass.size() == 5) {
        
        // 2. 모든 시도(m개)의 조건을 만족하는지 검사
        bool all_conditions_met = true;
        
        for (int i = 0; i < q.size(); ++i) { // i는 m번의 시도 인덱스
            int match_count = 0;
            
            // 3. 현재 시도 q[i]와 생성된 조합 current_pass 간의 일치하는 개수를 센다.
            for (int target : q[i]) {
                // current_pass는 오름차순 정렬이 보장되므로 binary_search 사용 가능
                if (binary_search(current_pass.begin(), current_pass.end(), target)) {
                    match_count++;
                }
            }
            
            // 4. 일치하는 개수가 시스템 응답 ans[i]와 다르면 조건을 불만족
            if (match_count != ans[i]) {
                all_conditions_met = false;
                break; // 다음 시도를 검사할 필요 없이 즉시 중단
            }
        }
        
        // 5. 모든 조건을 만족하면 결과 카운트 증가
        if (all_conditions_met) {
            result_count++;
        }
        return;
    }

    // 6. 재귀 호출: 다음 숫자를 선택
    // start_num부터 n까지의 숫자 중에서 다음 비밀 코드를 선택
    for (int i = start_num; i <= n; ++i) {
        
        // **가지치기 (Pruning)**: 남은 숫자들을 모두 뽑아도 목표 크기 5를 채울 수 없는 경우
        // current_pass.size() (현재 뽑은 개수) + (n - i + 1) (남은 선택 가능한 최대 개수) < 5 이면
        // (i가 증가함에 따라 이 조건은 점점 만족하기 쉬워지므로 early exit 가능)
        if (current_pass.size() + (n - i + 1) < 5) {
             break; 
        }

        current_pass.push_back(i);                      // 숫자 i를 조합에 추가
        generate_combination(n, q, ans, i + 1, current_pass, result_count); // 다음 숫자는 i+1부터 시작 (조합)
        current_pass.pop_back();                        // 백트래킹: i를 조합에서 제거
    }
}


int solution(int n, vector<vector<int>> q, vector<int> ans) {
    // 필요한 변수들을 solution 함수 내에서 선언하고 초기화
    vector<int> current_pass; // 현재 비밀 코드 조합 (5개)
    int result_count = 0;     // 결과값 저장 변수
    
    // 1부터 n까지의 숫자 중 5개를 뽑는 조합 생성 시작
    // n: 범위, q: 시도, ans: 응답, 1: 시작 숫자, current_pass: 조합, result_count: 결과
    generate_combination(n, q, ans, 1, current_pass, result_count); 
    
    return result_count;
}