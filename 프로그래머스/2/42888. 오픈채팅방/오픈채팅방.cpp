#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

typedef struct _data{
    string ac;
    string id;
}DATA;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<DATA> r;
    for(int i = 0; i < record.size(); i++){
        string tmp = record[i];
        
        stringstream ss(tmp);
        string word;
        vector<string> words;
        
        while(ss >> word){
            words.push_back(word);    
        }
        
        string ac, id, name;
        
        ac = words[0];
        id = words[1];
        
        if(ac != "Leave"){
            name = words[2];
        }
        
        
        if(ac != "Change")
            r.push_back({ac, id});
        
        if(ac == "Enter" || ac == "Change")
            m[id] = name;
    }
    
    for(int i = 0; i < r.size(); i++){
        string tmp = "";
        tmp += m[r[i].id];
        tmp += "님이 ";
        if(r[i].ac == "Enter"){
            tmp += "들어왔습니다.";
        }
        else{
            tmp += "나갔습니다.";
        }
        answer.push_back(tmp);
    }
    
    return answer;
}