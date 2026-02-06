#include <iostream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<long long> dist(N+1, 987654321987654321LL);
    vector<vector<pair<int ,int>>> graph(N+1);
    for(int i = 0; i < road.size(); i++){
        int from = road[i][0];
        int to = road[i][1];
        int c = road[i][2];
        
        graph[from].push_back({to, c});
        graph[to].push_back({from, c});
    }
    
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({1, 0});
    
    while(!pq.empty()){
        int x = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        
        if(dist[x] > K)
            continue;
        
        for(int i = 0; i < graph[x].size(); i++){
            int next = graph[x][i].first;
            int nd = graph[x][i].second;
            
            if(dist[next] == 987654321987654321LL || dist[x] + nd < dist[next]){
                dist[next] = dist[x] + nd;
                pq.push({next, dist[next]});
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(dist[i] <= K)
            answer++;
    }
       
    return answer;
}