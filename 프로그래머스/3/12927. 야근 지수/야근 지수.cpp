// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// long long solution(int n, vector<int> works) {
//     long long answer = 0;
    
//     long long tmp = 0;
//     int low = 1, high = 0;
//     for(int i = 0; i < works.size(); i++){
//         tmp += works[i];
//         high = max(high, works[i]);
//     }
//     if(tmp <= n)
//         return 0;
    
//     sort(works.begin(), works.end());
    
//     while(low <= high){
//         int mid = (low + high) / 2;
//     }
    
//     return answer;
// }

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long solution(int n, vector<int> works) {
    long long total_works = 0;
    int max_work = 0;
    for(int w : works) {
        total_works += w;
        max_work = max(max_work, w);
    }
    
    // 1. 모든 작업을 다 끝낼 수 있는 경우
    if (total_works <= n) return 0;

    // 2. 이분 탐색으로 기준값 X 찾기
    int low = 0, high = max_work;
    int x = max_work;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        long long needed = 0;
        
        for (int w : works) {
            if (w > mid) needed += (w - mid);
        }
        
        if (needed <= n) {
            x = mid; // 이 값으로 모든 작업을 X 이하로 만들 수 있음
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 3. X를 기준으로 작업량 조정 및 남은 시간(n) 계산
    long long used_n = 0;
    for (int &w : works) {
        if (w > x) {
            used_n += (w - x);
            w = x;
        }
    }
    
    long long rem_n = n - used_n; // 아직 더 뺄 수 있는 시간
    
    // 4. 남은 시간만큼 작업량이 X인 것들을 X-1로 변경
    for (int i = 0; i < works.size() && rem_n > 0; i++) {
        if (works[i] == x) {
            works[i]--;
            rem_n--;
        }
    }

    // 5. 피로도 계산
    long long answer = 0;
    for (int w : works) {
        if (w > 0) answer += (long long)w * w;
    }
    
    return answer;
}