#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0, server_cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> server_expire;
    for(int i = 0; i < players.size(); i++){
        if(!server_expire.empty()){
            if(server_expire.top().first <= i){
                server_cnt -= server_expire.top().second;
                server_expire.pop();
            }
        }
        int player = players[i];
        int inc_cnt = 0;
        if(player >= m){
            int inc_server = player / m;
            if(server_cnt < inc_server){
                inc_cnt = inc_server - server_cnt;
                server_cnt = inc_server;
                answer += inc_cnt;
                server_expire.push({i+k, inc_cnt});
            }
        }
        
        //cout << player << ' ' << server_cnt << ' ' << inc_cnt << endl;
    }
    return answer;
}