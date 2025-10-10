#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> index;
    for(int i = 0; i < friends.size(); i++){
        index[friends[i]] = i;
    }
    
    vector<vector<int>> g;
    g.resize(friends.size(), vector<int>(friends.size(), 0));
    vector<int> recieve;
    recieve.resize(friends.size(), 0);
    for(int i = 0; i < gifts.size(); i++){
        string tmp = "";
        for(int j = 0; j < gifts[i].length(); j++){
            if(gifts[i][j] == ' ')
                break;
            tmp += gifts[i][j];
        }
        string tmp1 = gifts[i].substr(tmp.length()+1);
        g[index[tmp]][index[tmp1]]++;
    }
    
    for(int i = 0; i < friends.size()-1; i++){
        for(int j = i+1; j < friends.size(); j++){
            if(i == j)
                continue;
            
            if(g[i][j] != g[j][i]){
                if(g[i][j] > g[j][i]){
                    recieve[i]++;
                }
                else if(g[i][j] < g[j][i])
                    recieve[j]++;
            }
            else{
                int i_cnt = 0, j_cnt = 0;
                
                for(int k = 0; k < friends.size(); k++){
                    if(i != k){
                        i_cnt += g[i][k];
                        i_cnt -= g[k][i];
                    }
                    
                    if(j != k){
                        j_cnt += g[j][k];
                        j_cnt -= g[k][j];
                    }
                }
                
                if(i_cnt > j_cnt){
                    recieve[i]++;
                }
                else if(i_cnt < j_cnt){
                    recieve[j]++;
                }
            }
        }
    }
    
    for(int i = 0; i < recieve.size(); i++)
        answer = max(answer, recieve[i]);
    
    return answer;
}