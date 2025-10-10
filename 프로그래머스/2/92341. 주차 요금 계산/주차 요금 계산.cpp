#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> table, total_t;
    
    for(int i = 0; i < records.size(); i++){
        string tmp = records[i];
        
        string hour = tmp.substr(0, 2);
        string min = tmp.substr(3, 2);
        string num = tmp.substr(6, 4);
        string stat = tmp.substr(11, tmp.length() - 10);
        int mins = stoi(min) + (stoi(hour) * 60);
        
        if(stat == "IN"){
            table[num] = mins;
        }
        else{
            map<string, int>::iterator it = table.find(num);
            table.erase(num);
            total_t[num] += mins - it->second;
        }
//                     int total_fee = 0;
//             total_fee += fees[1];
//             map<string, int>::iterator it = table.find(num);
//             int remaining_t = it->second - fees[0];
            
//             if(remaining_t > 0){
//                 total_fee += ((remaining_t / fees[2])+1) * fees[3];
//             }
            
//             total_fees[num] += total_fee;
//             cout << num << ' ' << total_fees[num] << endl;
//             table.erase(num);
    }
    int mins = stoi("59") + (stoi("23") * 60);
    for(auto i = table.begin(); i != table.end(); i++){
        total_t[i->first] += mins - i->second;
    }
    
    vector<pair<string, int>> res(total_t.begin(), total_t.end());
    sort(res.begin(), res.end(), cmp);
    
    for(int i = 0; i < res.size(); i++){
        int total_fee = 0;
        total_fee += fees[1];
        int remaining_t = res[i].second - fees[0];
    
        if(remaining_t > 0){
            if(remaining_t % fees[2] != 0)
                total_fee += ((remaining_t / fees[2])+1) * fees[3];
            else
                total_fee += ((remaining_t / fees[2])) * fees[3];
        }
        res[i].second = total_fee;
    }
    
    for(int i = 0; i < res.size(); i++){
        answer.push_back(res[i].second);
    }
    return answer;
}