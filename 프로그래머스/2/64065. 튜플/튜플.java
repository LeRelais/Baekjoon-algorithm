import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    Set<Integer> se = new HashSet<>();
    public int[] solution(String s) {
        int[] answer = {};
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a.length, b.length);
        });
        
        for(int i = 1; i < s.length()-1; i++){
            ArrayList<Integer> arr = new ArrayList<>();
            String num = "";
            if(s.charAt(i) == '{'){
                i++;
                while(s.charAt(i) != '}'){
                    if(s.charAt(i) == ','){
                        arr.add(Integer.parseInt(num));
                        num = "";
                    }
                    else
                        num += s.charAt(i);
                    i++;
                }
                arr.add(Integer.parseInt(num));
            }

            if(arr.size() != 0){
                int[] tmp = new int[arr.size()];
                int idx = 0;
                for(int x : arr){
                    tmp[idx++] = x;
                }
                pq.add(tmp);
            }
        }
        
        int prev = -1;
        answer = new int[pq.size()];
        int a_idx = 0;
        while(!pq.isEmpty()){
            int[] tmp = pq.poll();
            for(int x : tmp){
                if(prev != x && !se.contains(x)){
                    prev = x;
                    se.add(x);
                    answer[a_idx++] = x;
                    break;
                }
            }
        }
            
        return answer;
    }
}