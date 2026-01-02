#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    vector<int> visited(1000001, -1);
    visited[x] = 0;
    queue<int> q;
    q.push(x);
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
        
        if(num == y){
            answer = visited[y];
            break;
        }
        
        if(num*2 <= y && visited[num * 2] == -1){
            visited[num*2] = visited[num]+1;
            q.push(num*2);
        }
        if(num*3 <= y && visited[num * 3] == -1){
            visited[num*3] = visited[num]+1;
            q.push(num*3);
        }
        if(num+n <= y && visited[num + n] == -1){
            visited[num + n] = visited[num]+1;
            q.push(num + n);
        }
    }
    
    return answer;
}