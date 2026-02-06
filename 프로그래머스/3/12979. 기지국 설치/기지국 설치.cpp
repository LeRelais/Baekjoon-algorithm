#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int coverage = 2*w+1;
    int cur = 1;
    
    for(int station: stations){
        if(cur < station - w){
            int len = station-w-cur;
            if(len % coverage == 0)
                answer += len / coverage;
            else
                answer += (len / coverage) + 1;
        }
        cur = station + w + 1;
    }
    
    if(cur <= n){
        int len = n - cur + 1;
        if(len % coverage == 0)
            answer += len / coverage;
        else
            answer += (len / coverage) + 1;
        
    }
    
    return answer;
}