#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    multiset<int> ms;
    
    for(int i = 0; i < B.size(); i++){
        ms.insert(B[i]);    
    }
    
    for(int i = 0; i < A.size(); i++){
        int val = A[i];
        auto it = ms.upper_bound(val);
        if(it != ms.end()){
            ms.erase(it);
            answer++;    
        }
        
    }
        
    return answer;
}