import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    Map<String, Integer> m = new HashMap<>();
    
    public void initMap(){
        m.put("zero", 0);
        m.put("one", 1);
        m.put("two", 2);
        m.put("three", 3);
        m.put("four", 4);
        m.put("five", 5);
        m.put("six", 6);
        m.put("seven", 7);
        m.put("eight", 8);
        m.put("nine", 9);
    }
    
    public int solution(String s) {
        int answer = 0;
        
        initMap();
        
        String tmp = "";
        String stmp = "";
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) >= '0' && s. charAt(i) <= '9'){ 
                tmp += s.charAt(i);
            }
            else{
                stmp += s.charAt(i);
                
                if(m.get(stmp) != null){
                    int num = m.get(stmp);
                    tmp += num;
                    stmp = "";
                }
            }
        }
        
        answer = Integer.parseInt(tmp);
        return answer;
    }
}