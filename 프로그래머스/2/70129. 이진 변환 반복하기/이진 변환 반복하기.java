import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = {};
        int cntTransform = 0;
        int cntZeros = 0;
        
        while(!s.equals("1")){
            int len = s.length();
            int zeroCnt = 0;
            
            for(int i = 0; i < s.length(); i++){
                if(s.charAt(i) == '0')
                    zeroCnt++;
            }
            
            cntZeros += zeroCnt;
            cntTransform++;
            
            s = Integer.toBinaryString(len - zeroCnt);
        }
        
        
        return new int[]{cntTransform, cntZeros};
    }
}