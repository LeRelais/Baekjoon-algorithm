#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(int i = 0; i < scoville.size(); i++){
        q.push(scoville[i]);
    }
    
    int cnt = 0;
    while(q.top() < K && q.size() >= 2){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        
        long long tmp = (long long)a + ((long long)b * 2);
        q.push(tmp);
        cnt++;
    }
    if(q.top() < K)
        answer = -1;
    else
        answer = cnt;
    return answer;
}