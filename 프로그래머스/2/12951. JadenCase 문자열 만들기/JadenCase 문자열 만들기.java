import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        StringTokenizer st = new StringTokenizer(s);
        boolean isBlank = true;
        
        for(String tmp: s.split("")){
            if(tmp.equals(" ")){
                answer += " ";
                isBlank = true;
            }
            else{
                if(isBlank == true){
                    answer += tmp.toUpperCase();
                    isBlank = false;
                }
                else{
                    answer += tmp.toLowerCase();
                }
            }
        }
        
        return answer;
    }
}