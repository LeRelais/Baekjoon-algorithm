#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

bool dfs(vector<vector<string>> tickets, string cur, vector<string> &answer, vector<bool> &visited, int cnt){
    answer.push_back(cur);
    
    if(cnt == tickets.size()){
        return true;
    }
    
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] == cur && !visited[i]){
            visited[i] = true;
            
            bool res = dfs(tickets, tickets[i][1], answer, visited, cnt+1);
            if(res) return true;
            visited[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size(), false);
    for(int i = 0; i < tickets.size(); i++){
        cout << tickets[i][0] << ' ' << tickets[i][1] << endl;
    }
    
    dfs(tickets, "ICN", answer, visited, 0);
    return answer;
}