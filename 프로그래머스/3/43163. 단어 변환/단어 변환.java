import java.lang.*;
import java.util.*;
import java.io.*;

class DATA{
    String cur;
    int cnt;
    
    public DATA(String cur, int cnt){
        this.cur = cur;
        this.cnt = cnt;
    }
}

class Solution {
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        Boolean flag = false;
        for(int i = 0; i < words.length; i++){
            if(words[i].equals(target)){
                flag = true;
                break;
            }
        }
        
        if(flag == false)
            return 0;
        
        answer = find_word(begin, target, words);
        return answer;
    }
    
    public int find_word(String begin, String target, String[] words){
        PriorityQueue<DATA> pq = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a.cnt, b.cnt);
        });
        boolean[] used = new boolean[words.length+1];
        pq.add(new DATA(begin, 0));
        int cntTransform = 0;
        
        while(!pq.isEmpty()){
            DATA tmp = pq.poll();
            String cur = tmp.cur;
            int cnt = tmp.cnt;
            
            if(cur.equals(target)){
                cntTransform = cnt;
                break;
            }
            
            for(int i = 0; i < words.length; i++){
                if(used[i] == true)
                    continue;
                
                int same_cnt = 0;
                for(int j = 0; j < cur.length(); j++){
                    if(cur.charAt(j) == words[i].charAt(j))
                        same_cnt++;
                }
                
                if(same_cnt == cur.length()-1){
                    used[i] = true;
                    pq.add(new DATA(words[i], cnt+1));
                }
            }
        }
        return cntTransform;
    }
}