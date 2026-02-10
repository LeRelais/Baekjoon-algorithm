import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        int low = 1, high = 200000000;
        
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
    public Boolean canCross(int[] stones, int k, int mid){
        int cnt = 0;
        
        for(int stone : stones){
            if(stone < mid){
                cnt++;
                
                if(cnt >= k)
                    return false;
            }
            else
                cnt = 0;
        }
        return true;
    }
}