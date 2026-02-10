#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp{
  bool operator()(const vector<int> &a, const vector<int> &b){
      return a[2] > b[2];
  }  
};
int parent[100];

int getParent(int x){
    if (x == parent[x])
        return x;
    return parent[x] = getParent(parent[x]);    
}

void comb_parent(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);
    
    if(pa != pb){
        if(pa > pb){
            parent[pa] = pb;
        }
        else
            parent[pb] = pa;
    }
    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for(int i = 0; i < n; i++)
        parent[i] = i;
    
    for(int i = 0; i < costs.size(); i++)
        pq.push(costs[i]);
    
    vector<vector<int>> edges;
    
    while(!pq.empty()){
        if(edges.size() == n-1)
            break;
        
        vector<int> tmp = pq.top();
        pq.pop();
        if(getParent(tmp[0]) != getParent(tmp[1])){
            edges.push_back(tmp);
            answer += tmp[2];
            comb_parent(tmp[0], tmp[1]);
        }
    }
    return answer;
}