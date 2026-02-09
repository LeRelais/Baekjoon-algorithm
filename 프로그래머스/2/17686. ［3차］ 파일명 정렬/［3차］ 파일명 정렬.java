import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = {};
        
        Arrays.sort(files, (f1, f2) -> {
            String[] parts1 = splitFileName(f1);
            String[] parts2 = splitFileName(f2);
            
            int headCmp = parts1[0].equalsIgnoreCase(parts2[0]) ? 0 : parts1[0].compareToIgnoreCase(parts2[0]);
            if(headCmp != 0)
                return headCmp;
            int num1 = Integer.parseInt(parts1[1]);
            int num2 = Integer.parseInt(parts2[1]);
            
            return Integer.compare(num1, num2);
        });
        
        answer = files;
        
        return answer;
    }
    
    public String[] splitFileName(String file){
        int idx = 0;
        String head = "";
        String num = "";
        for(int i = idx; i < file.length(); i++){
            char c = file.charAt(i);
            if(c >= '0' && c <= '9')
                break;
            head += c;
            idx += 1;
        }
        
        for(int i = idx; i < file.length(); i++){
            char c = file.charAt(i);
            if(!(c >= '0' && c <= '9') || num.length() >= 5)
                break;
            num += c;
            idx += 1;
        }
        
        return new String[]{head, num};
    }
}