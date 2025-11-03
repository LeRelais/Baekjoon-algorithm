#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, a, b, c;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

typedef struct _data{
    int san;
    int cost;
    int x;
}DATA;

struct cmp{
  bool operator()(const DATA &a, const DATA &b){
      return a.cost > b.cost;
  }  
};

//문제 input 입력받기, 그 외 사용할 vector 및 변수 초기화 작업 진행
void init(){
    cin >> n >> m >> a >> b >> c;
    int from, to, value;
    graph.resize(n+1);
    dist.resize(n+1, 987654321);
    
    // 문제에선 양방향이라고 언급했지만 이미 지나간 길을 다시 지나갈 일이 없기 때문에 단방향 그래프 구성
    for(int i = 0; i < n; i++){
        cin >> from >> to >> value;
        graph[from].push_back({to, value});
    }    
}

void solve(){
    priority_queue<DATA, vector<DATA>, cmp> pq;
    pq.push({0,0,1});
    int res = 987654321;
    while(!pq.empty()){
        int san = pq.top().san;
        int cost = pq.top().cost;
        int x = pq.top().x;
        pq.pop();
        
        if(x == b){
            res = min(res, san);
            continue;
        }
        
        for(int i = 0; i < graph[x].size(); i++){
            int next = graph[x][i].first;
            int n_cost = graph[x][i].second;
            
            if(dist[next] > cost + n_cost && cost + n_cost <= c){
                dist[next] = cost + n_cost;
                int n_san = max(san, n_cost);
                pq.push({n_san, dist[next], next});
            }
        }
    }
    
    if(res == 987654321)
        cout << -1;
    else
        cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}