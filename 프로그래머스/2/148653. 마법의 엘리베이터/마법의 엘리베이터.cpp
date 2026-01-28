#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int cur;
    int cost;
};

int solution(int storey) {
    queue<Node> q;
    q.push({storey, 0});
    
    // dist[층수] = 최소 돌 개수
    unordered_map<int, int> dist;
    dist[storey] = 0;
    
    int min_stone = 1e9;
    
    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        
        // 이미 더 적은 비용으로 도달한 적이 있다면 무시
        if (dist.count(node.cur) && dist[node.cur] < node.cost) continue;
        if (node.cost >= min_stone) continue;

        if (node.cur == 0) {
            min_stone = min(min_stone, node.cost);
            continue;
        }
        
        int last = node.cur % 10;
        
        // 1. 내림
        int next1 = node.cur / 10;
        int cost1 = node.cost + last;
        if (!dist.count(next1) || dist[next1] > cost1) {
            dist[next1] = cost1;
            q.push({next1, cost1});
        }
        
        // 2. 올림
        int next2 = node.cur / 10 + 1;
        int cost2 = node.cost + (10 - last);
        if (!dist.count(next2) || dist[next2] > cost2) {
            dist[next2] = cost2;
            q.push({next2, cost2});
        }
    }
    
    return min_stone;
}