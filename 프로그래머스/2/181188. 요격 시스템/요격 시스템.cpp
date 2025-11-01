#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), cmp);
    int answer = 1;
    int cur_end = targets[0][1];
    
    for(int i = 1; i < targets.size(); i++){
        if(targets[i][0] >= cur_end){
            cur_end = targets[i][1];
            answer++;
        }
    }
    return answer;
}