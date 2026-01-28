#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    int cmp = col-1;
    sort(data.begin(), data.end(), [cmp](const vector<int> &a, const vector<int> &b){
        if(a[cmp] == b[cmp]){
            return a[0] > b[0];
        }
        return a[cmp] < b[cmp];
    });    
    
    
    for(int i = row_begin; i <= row_end; i++){
        int tmp = 0;
        for (int j = 0; j < data[i-1].size(); j++) {
            tmp += (data[i-1][j] % i);
        }
        answer ^= tmp;
    }
    
    return answer;
}