import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {
    TreeMap<Integer, Integer> tm = new TreeMap<>();
    
    public int solution(int[] A, int[] B) throws Exception{
        int answer = 0;
        
        for(int i = 0; i < B.length; i++){
            tm.put(B[i], tm.getOrDefault(B[i], 0) + 1);
        }
        
        for(int i = 0; i < A.length; i++){
            int val = A[i];
            Integer target = tm.higherKey(val);
            if(target != null){
                int count = tm.get(target);
                if(count > 0){
                    tm.put(target, count-1);
                    answer += 1;
                    
                    if(count-1 == 0)
                        tm.remove(target);
                }
            }
        }
        
        return answer;
    }
}