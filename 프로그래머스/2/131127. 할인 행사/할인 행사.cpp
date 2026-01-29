#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> lists;
    for(int i = 0; i < want.size(); i++){
        lists[want[i]] = number[i];
    }
    for(int i = 0; i <= discount.size()-10; i++){
        map<string, int> tmp;
        
        for(int j = i; j < i+10; j++){
            tmp[discount[j]]+=1;
        }

        int flag = 1;
        for(auto iter = lists.begin(); iter != lists.end(); iter++){
            if(tmp[iter->first] != iter->second){
                flag = 0;
                break;
            }
        }
        
        if(flag)
            answer++;
    }
    
    return answer;
}