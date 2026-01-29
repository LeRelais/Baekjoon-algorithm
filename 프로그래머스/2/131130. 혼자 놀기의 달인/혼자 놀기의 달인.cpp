#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[101];

int make_group(int i, const vector<int> &cards, int cnt){
    if(visited[i]){
        return cnt;
    }
    //cout << i << ' ' << cards[i] << '\n';
    visited[i] = 1;
    int tmp = make_group(cards[i], cards, cnt+1);
    return tmp;
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> cards_tmp;
    vector<int> cnts;
    cards_tmp.push_back(0);
    for(int i = 0; i < cards.size(); i++){
        cards_tmp.push_back(cards[i]);
    }
    
    for(int i = 1; i < cards_tmp.size(); i++){
        if(!visited[i]){
            int cnt = make_group(i, cards_tmp, 1);
            //cout << cnt << endl;
            cnts.push_back(cnt-1);
        }
    }
    
    if(cnts.size() <= 1)
        return 0;
    
    sort(cnts.begin(), cnts.end());
    answer = cnts[cnts.size()-1] * cnts[cnts.size()-2];
    return answer;
}