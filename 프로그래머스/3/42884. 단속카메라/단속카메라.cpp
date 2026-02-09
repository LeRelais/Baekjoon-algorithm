#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    answer = 1;
    int f = routes[0][0];
    int b = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(routes[i][0] > b){
            f = routes[i][0];
            b = routes[i][1];
            answer++;
        }
    }
    return answer;
}