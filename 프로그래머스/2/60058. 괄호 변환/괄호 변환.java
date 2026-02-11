import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    public String solution(String p) {
        String answer = "";
        
        if(p.isEmpty())
            return "";
        
        int splitIdx = splitStr(p);
        String u = p.substring(0, splitIdx+1);
        String v = p.substring(splitIdx+1);
        
        if(correctStr(u)){
            return u + solution(v);
        }else{
            StringBuilder sb = new StringBuilder();
            sb.append("(");
            sb.append(solution(v));
            sb.append(")");
            
            sb.append(reverseStr(u));
            return sb.toString();
        }
        
    }
    
    public int splitStr(String p){
        int open = 0, close = 0;
        
        for(int i = 0; i < p.length(); i++){
            if(p.charAt(i) == '(')
                open++;
            else{
                close++;
            }
            if(open > 0 && close == open) return i;
        }
        
        return p.length()-1;
    }
    
    public boolean correctStr(String str){
        int cnt = 0;
        
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '(')
                cnt++;
            else{
                if(cnt == 0)
                    return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
    
    public String reverseStr(String u){
        String tmp = "";
        tmp = u.substring(1, u.length()-1);
        String res = "";
        for(int i = 0; i < tmp.length(); i++){
            if(tmp.charAt(i) == '('){
                res += ')';
            }
            else
                res += '(';
        }
        
        return res;
    }
}