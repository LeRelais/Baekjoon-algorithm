#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int t, k, w, h, start_y, start_x;
map<char, int> battleships;
char place[1001][1001];
int visited[1001][1001];

int dir_y[] = {-1,1,0,0};
int dir_x[] = {0,0,-1,1};

int find_min_dist(int col, int row){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int res = 987654321;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            visited[i][j] = 987654321;
        }
    }
    
    visited[col][row] = 0;
    pq.push({0, {col, row}});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        //cout << "cur : " << y << ' ' << x << ' ' << dist << endl;
        pq.pop();
        
        if(y == h-1 || x == w-1 || y == 0 || x == 0){
            //cout << y << ' ' << x << ' ' << dist << endl;
            res = min(res, dist);
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dir_y[i];
            int nx = x + dir_x[i];
            
            if(visited[ny][nx] > visited[y][x] + battleships[place[ny][nx]]){
                visited[ny][nx] = visited[y][x] + battleships[place[ny][nx]];
                pq.push({visited[ny][nx], {ny,nx}});
            }
        }
    }
    
    return res;
}

int main() {
    cin >> t;
    char tmp;
    int num;
    string s_in;
    
    while(t--){
        cin >> k >> w >> h;
    
        for(int i = 0; i < k; i++){
            cin >> tmp >> num;
            battleships[tmp] = num;
        }
        
        for(int i = 0; i < h; i++){
            cin >> s_in;
        
            for(int j = 0; j < w; j++){
                place[i][j] = s_in[j];
                if(s_in[j] == 'E'){
                    start_y = i;
                    start_x = j;
                }
            }
        }
    
        cout << find_min_dist(start_y, start_x) << endl;
    }
    
    return 0;
}