import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        Map<String, Integer> m = new HashMap<>();
        
        for(String s : participant){
            if(!m.containsKey(s)){
                m.put(s, 1);
            }
            else{
                int tmp = m.get(s);
                m.put(s, tmp+1);
            }
        }
        
        for(String s : completion){
            int tmp = m.get(s);
            m.put(s, tmp-1);
        }
        
        for(String key : m.keySet()){
            if(m.get(key) != 0){
                answer = key;
                break;
            }
        }
        
        return answer;
    }
}