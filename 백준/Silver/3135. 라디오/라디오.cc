#include <iostream>
#include <queue>

using namespace std;

int visited[1001], a, b, n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for(int i = 0; i <= 1000; i++){
        visited[i] = 987654321;
    }
    cin >> a >> b >> n;
    
    queue<int> q;
    int channel;
    for(int i = 0; i < n; i++){
        cin >> channel;
        visited[channel] = 1;
        q.push(channel);
    }
    visited[a] = 0;
    q.push(a);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(visited[x+1] > visited[x]+1){
            visited[x+1] = visited[x] + 1;
            q.push(x+1);
        }
        
        if(visited[x-1] > visited[x]+1){
            visited[x-1] = visited[x] + 1;
            q.push(x-1);
        }
    }
    cout << visited[b];
    return 0;
}