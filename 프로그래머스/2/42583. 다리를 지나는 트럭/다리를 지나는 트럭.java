import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {
    Deque<int[]> q = new ArrayDeque<>();
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int idx = 0;
        int w_sum = 0;
        while(true){
            if(idx == truck_weights.length)
                break;
            
            if(q.peekFirst() != null && answer - q.peekFirst()[0] == bridge_length){
                int[] tmp = q.pollFirst();
                w_sum -= tmp[1];
            }
            
            if(q.isEmpty()){
                q.addLast(new int[]{answer, truck_weights[idx]});
                w_sum += truck_weights[idx];
                idx+=1;
            }
            else{
                if(weight - w_sum >= truck_weights[idx]){
                    q.addLast(new int[]{answer, truck_weights[idx]});
                     w_sum += truck_weights[idx];
                    idx+=1;
                }
            }
            answer++;
        }
        
        return answer + bridge_length;
    }
}