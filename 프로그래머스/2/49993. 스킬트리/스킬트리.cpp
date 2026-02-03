#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    unordered_map<char, vector<char>> topo;
    unordered_map<char, int> cnt, cnt_tmp;
    for(int i = 0; i < skill.length()-1; i++){
        char pre = skill[i];
        char trail = skill[i+1];
        
        topo[pre].push_back(trail);
        cnt_tmp[trail]++;
    }
    
    for(int i = 0; i < skill_trees.size(); i++){
        int flag = 1;
        cnt = cnt_tmp;
        for(int j = 0; j < skill_trees[i].length(); j++){
            char tmp = skill_trees[i][j];
            if(topo.count(tmp)){
                cnt[topo[tmp][0]] -= 1;
            }
            
            if(cnt[tmp] > 0){
                flag = 0;
                break;
            }
        }
        
        if(flag){
            answer++;
            //cout << i << endl;
        }
    }
    return answer;
}