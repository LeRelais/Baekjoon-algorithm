#include <string>
#include <vector>

using namespace std;

bool canCross(const vector<int> &stones, int k, int mid){
    int count = 0;
    for(int stone : stones){
        if(stone < mid){
            count++;
            if(count >= k)
                return false;
        }
        else
            count = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int low = 1, high = 200000000;
    vector<int> tmp;
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(canCross(stones, k, mid)){
            low = mid + 1;
            answer = mid;
        }
        else{
            high = mid - 1;
        }
    }
    
    return answer;
}