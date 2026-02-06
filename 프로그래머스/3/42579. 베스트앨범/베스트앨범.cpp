#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &v1, const pair<int, int> &v2){
    if(v1.second == v2.second){
        return v1.first < v2.first;
    }
    return v1.second > v2.second;
}

bool cmp1(const pair<string, int> &v1, const pair<string, int> &v2){
    return v1.second > v2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> m;
    map<string, int> cnt;
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]].push_back({i, plays[i]});
        cnt[genres[i]] += plays[i];
    }
    vector<pair<string, int>> cntMap(cnt.begin(), cnt.end());
    sort(cntMap.begin(), cntMap.end(), cmp1);
    
    for(auto it = m.begin(); it != m.end(); it++){
        sort(it->second.begin(), it->second.end(), cmp);
    }
    
    for(auto it = cntMap.begin(); it != cntMap.end(); it++){
        answer.push_back(m[it->first][0].first);
        if(m[it->first].size() > 1){
            answer.push_back(m[it->first][1].first);
        }
    }
    return answer;
}