#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    answer.resize(prices.size());
    stack<pair<int, int>> st;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    st.push({prices[0], 0});
    pq.push({prices[0], 0});
    
    for(int i = 1; i < prices.size(); i++){
        if(pq.top().first > prices[i]){
            while(pq.top().first > prices[i] && !pq.empty()){
                answer[pq.top().second] = i - pq.top().second;
                pq.pop();
            }
        }
        pq.push({prices[i], i});
    }
    
    while(!pq.empty()){
        answer[pq.top().second] = prices.size() - 1 - pq.top().second;
        pq.pop();
    }
    return answer;
}