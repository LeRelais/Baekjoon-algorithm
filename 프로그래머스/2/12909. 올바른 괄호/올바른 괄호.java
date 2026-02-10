import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    Deque<Character> st = new ArrayDeque<>();
    boolean solution(String s) {
        boolean answer = true;
        
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ')'){
                if(st.isEmpty()){
                    answer = false;
                    break;
                }
                st.pollLast();
            }
            else{
                st.push('(');
            }
        }        
        
        if(!st.isEmpty())
            answer = false;
        
        return answer;
    }
}