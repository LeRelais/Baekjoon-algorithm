#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int cont = 0;
    int cur_t = 1;
    int idx = 0;
    answer = health;
    int flag = 1;
    for(int i = 1; ; i++){
        if(cur_t == attacks[attacks.size()-1][0]){
            answer -= attacks[attacks.size()-1][1];
            break;
        }
        
        if(cur_t == attacks[idx][0]){
            cont = 0;
            answer -= attacks[idx][1];
            if(answer <= 0){
                flag = 0;
                break;
            }
            idx++;
        }
        else{
            cont++;
            if(answer + bandage[1] <= health)
                answer += bandage[1];
            else
                answer = health;
            
            if(cont == bandage[0]){
                cont = 0;
                if(answer + bandage[2] <= health)
                    answer += bandage[2];
                else
                    answer = health;
            }
        }
        cur_t++;
        //cout << i << ' ' << answer << ' ' << cont << endl;
    }
    if(!flag || answer <= 0)
        answer = -1;
    return answer;
}