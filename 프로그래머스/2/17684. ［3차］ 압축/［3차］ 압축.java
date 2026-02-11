import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    HashMap<String, Integer> m = new HashMap<>();
    
    public void initMap(){
        for(int i = 1; i <= 26; i++){
            String tmp = "";
            tmp += (char)((int)'A' + i - 1);
            m.put(tmp, i);
        }
    }
    
    public int[] solution(String msg) {
        int[] answer = {};
        
        initMap();
        
        String tmp = "";
        String prev = "";
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int i = 0; i < msg.length(); i++){
            tmp = "";
            while(i < msg.length() && m.containsKey(tmp + msg.charAt(i))){
                tmp += msg.charAt(i);
                i++;
            }
            arr.add(m.get(tmp));
            if(i < msg.length())
                m.put(tmp + msg.charAt(i), m.size()+1);
            i--;
        }

        
        answer = new int[arr.size()];
        for(int i = 0; i < arr.size(); i++){
            answer[i] = arr.get(i);
        }
        return answer;
    }
}