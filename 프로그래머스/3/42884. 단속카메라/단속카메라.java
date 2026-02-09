import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        Arrays.sort(routes, (a, b) -> {
            if(a[1] == b[1]){
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[1], b[1]); 
        });
        
        int b = routes[0][1];
        for(int i = 1; i < routes.length; i++){
            int f = routes[i][0];
            
            if(f > b){
                b = routes[i][1];
                answer++;
            }
        }
        
        return answer+1;
    }
}