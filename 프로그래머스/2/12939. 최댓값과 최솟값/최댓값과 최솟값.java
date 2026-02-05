import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        StringTokenizer st = new StringTokenizer(s);
        int max_i = Integer.parseInt(st.nextToken());
        int min_i = max_i;
        
        while(st.hasMoreTokens()){
            int tmp = Integer.parseInt(st.nextToken());
            max_i = Math.max(max_i, tmp);
            min_i = Math.min(min_i, tmp);
        }
        answer += min_i + " " + max_i;
        return answer;
    }
}