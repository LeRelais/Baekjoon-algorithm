import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        
        Arrays.sort(rocks);
        
        int low = 1, high = distance;
        
        while(low <= high){
            // mid로 거리
            int mid = (low + high) / 2;
            int cnt = 0;
            int prev = 0;
            
            for(int i = 0; i < rocks.length; i++){
                int dist_diff = rocks[i] - prev;
                if(dist_diff < mid){
                    cnt++;
                }
                else
                    prev = rocks[i];
            }
            
            if(distance - prev < mid)
                cnt++;
            
            if(cnt <= n){
                low = mid + 1;
                answer = mid;
            }
            else{
                high = mid - 1;
            }
        }
        
        return answer;
    }
}