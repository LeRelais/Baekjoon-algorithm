#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct _data{
    int r;
    int cnt;
    int round;
}DATA;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    priority_queue<int, vector<int>, less<int>> pq;
    
    int remaining = n, cnt = k, idx;
    
    for(int i = 0; i < enemy.size(); i++){
        n -= enemy[i];
        pq.push(enemy[i]);
        if(n < 0){
            if(cnt > 0){
                cnt -= 1;
                if(!pq.empty()){
                    n += pq.top();
                    pq.pop();
                }
            }
            else{
                answer = i;
                break;
            }
        }
    }
    
    return answer;
}