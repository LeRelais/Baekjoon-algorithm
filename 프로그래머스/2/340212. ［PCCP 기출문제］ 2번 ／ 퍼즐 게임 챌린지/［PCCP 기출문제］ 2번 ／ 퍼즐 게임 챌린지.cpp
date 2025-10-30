#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_d;

bool check(int level, const vector<int> &diffs, const vector<int> &times, long long limit){
    long long total = 0;
    long long time_prev = 0;
    for(int i = 0; i < diffs.size(); i++){
        time_prev = (i == 0) ? 0 : times[i-1];
        long long diff = diffs[i];
        long long time_cur = times[i];
        long long current_time;
        
        if(level >= diff){
            current_time = time_cur;
        }
        else{
            long long mistake_cnt = diffs[i] - level;
            current_time = (time_prev+time_cur) * mistake_cnt + time_cur;
        }
        total += current_time;
        if(total > limit)
            return false;
    }
    return total <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    for(int i = 0; i < diffs.size(); i++){
        max_d = max(max_d, diffs[i]);
    }
    int low = 1;
    int high = max_d;
    answer = high;
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(check(mid, diffs, times, limit)){
            answer = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return answer;
}