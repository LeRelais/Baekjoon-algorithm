#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    set<string> cmd;
    map<string, int> reported_cnt;
    map<string, vector<string>> reported;
    for(int i = 0; i < report.size(); i++){
        if(cmd.find(report[i]) != cmd.end())
            continue;
        cmd.insert(report[i]);
        string tmp1 = "", tmp2;
        for(int j = 0; j < report[i].length(); j++){
            if(report[i][j] == ' ')
                break;
            tmp1 += report[i][j];
        }
        tmp2 = report[i].substr(tmp1.length()+1);
        reported[tmp1].push_back(tmp2);
        reported_cnt[tmp2]++;
    }
    
    for(int i = 0; i < id_list.size(); i++){
        if(reported.find(id_list[i]) == reported.end())
            answer.push_back(0);
        else{
            int cnt = 0;
            map<string, vector<string>>::iterator it = reported.find(id_list[i]);
            for(int j = 0; j < it->second.size(); j++){
                string target = it->second[j];
                if(reported_cnt[target] >= k)
                    cnt++;
            }
            //vector<string> target = it->second;
            answer.push_back(cnt);
        }
    }
    return answer;
}