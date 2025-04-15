#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

map<string, int> scores;
int n, m, k, score, res, max_score, min_score;
string subject;
vector<string> opened_subjects;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.second > b.second;
}

int main() {
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        cin >> subject >> score;
        scores[subject] = score;
    }
    
    for(int i = 0; i < k ; i++){
        cin >> subject;
        res += scores[subject];
        scores.erase(subject);
    }
    
    vector<pair<string, int>> v(scores.begin(), scores.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < m-k; i++){
        max_score += v[i].second;
    }
    
    int tmp = 0;
    for(int i = v.size()-1; i >= 0; i--){
        if(tmp + k == m)
            break;
        min_score += v[i].second;
        tmp++;
    }
    
    cout << res + min_score << ' ' << res + max_score;
    return 0;
}