import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    Queue<Integer> q = new LinkedList<>();
    ArrayList<Integer> tmp = new ArrayList<>();
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int cnt = 0;
        for(int i = 0; i < progresses.length; i++){
            int t = (100-progresses[i]) / speeds[i];
            if((100-progresses[i]) % speeds[i] != 0)
                t += 1;
            
            if(q.isEmpty()){
                q.add(t);
            }
            else{
                if(t > q.peek()){
                    while(!q.isEmpty()){
                        cnt += 1;
                        q.poll();
                    }
                    tmp.add(cnt);
                    cnt = 0;
                }
                q.add(t);
            }
        }
        
        cnt = 0;
        while(!q.isEmpty()){
            cnt += 1;
            q.poll();
        }
        tmp.add(cnt);
        
        answer = new int[tmp.size()];
        for(int i = 0; i < tmp.size(); i++)
            answer[i] = tmp.get(i);
        return answer;
    }
}