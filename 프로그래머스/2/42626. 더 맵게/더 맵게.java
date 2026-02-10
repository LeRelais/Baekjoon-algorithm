import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        for(int i = 0; i < scoville.length; i++)
            pq.add(scoville[i]);
        
        if(pq.size() == 1){
            if(pq.peek() < K)
                answer = -1;
        }
        else{
            while(pq.size() != 1){
                int a = pq.peek();
                if(a >= K)
                    break;
                pq.poll();
                int b = pq.poll();
                
                pq.add(a + (b * 2));
                answer += 1;
            }
            if(pq.peek() < K)
                answer = -1;
        }
        return answer;
    }
}