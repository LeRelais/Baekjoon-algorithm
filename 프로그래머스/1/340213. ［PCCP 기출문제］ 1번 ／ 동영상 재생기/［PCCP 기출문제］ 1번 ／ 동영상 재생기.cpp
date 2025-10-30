#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    string tmp;
    tmp = video_len.substr(0, 2);
    
    int video_t, pos_t, start_t, end_t;
    video_t = stoi(tmp) * 60 + stoi(video_len.substr(3));
    pos_t = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3));
    start_t = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3));
    end_t = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3));
    
    if(pos_t >= start_t && pos_t < end_t)
        pos_t = end_t;
    
    for(int i = 0; i < commands.size(); i++){
        string command = commands[i];
        
        if(command == "next"){
            if(pos_t + 10 >= video_t)
                pos_t = video_t;
            else
                pos_t += 10;
        }
        else{
            if(pos_t - 10 <= 0)
                pos_t = 0;
            else
                pos_t -= 10;  
        }
        
        if(pos_t >= start_t && pos_t < end_t)
            pos_t = end_t;
    }
    if(pos_t / 60 < 10)
        answer = "0" + to_string(pos_t / 60);
    else
        answer = to_string(pos_t / 60);
    answer += ":";
    if(pos_t%60 < 10)
        tmp = "0" + to_string(pos_t % 60);
    else
        tmp = to_string(pos_t % 60);
    answer += tmp;
    return answer;
}