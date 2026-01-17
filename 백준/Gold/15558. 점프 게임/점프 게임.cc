#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, k;
vector<int> board[2], visited[2];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    string str;
    
    for(int i = 0; i < 2; i++){
        board[i].resize(n+1, 0);
        visited[i].resize(n+1, 0);
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            board[i][j+1] = str[j] - '0';
        }
    }
    
    int t = 0;
    visited[0][1] = 1;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 1}, 0});
    int flag = 0;
    while(!q.empty()){
        int side = q.front().first.first;
        int x = q.front().first.second;
        int cur_t = q.front().second;
        
        q.pop();
        //cout << side << ' ' << x << endl;
        if(x+1 > n || x + k > n){
            flag = 1;
            break;
        }
        
        if(x+1 > cur_t+1 && board[side][x+1] && !visited[side][x+1]){
            visited[side][x+1] = 1;
            q.push({{side, x+1}, cur_t+1});
        }
        
        if(x-1 > cur_t+1 && board[side][x-1] && !visited[side][x-1]){
            visited[side][x-1] = 1;
            q.push({{side, x-1}, cur_t+1});
        }
                
        if(x+k > cur_t+1 && board[!side][x+k] && !visited[!side][x+k]){
            visited[!side][x+k] = 1;
            q.push({{!side, x+k}, cur_t+1});
        }
        t++;
    }
    
    cout << flag << endl;
    return 0;
}