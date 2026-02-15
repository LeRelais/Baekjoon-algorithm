import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    public long solution(int n, int m, int x, int y, int[][] queries) {
        long answer = -1;
        
        long r1 = x;
        long r2 = x;
        long c1 = y;
        long c2 = y;
        for(int i = queries.length-1; i >= 0; i--){
            int dir = queries[i][0];
            int dx = queries[i][1];
            
            if(dir == 0){
                    if (c1 != 0) c1 += dx;
                    c2 = Math.min(m - 1, c2 + dx);
            }
            else if(dir == 1){
                if (c2 != m - 1) c2 -= dx;
                c1 = Math.max(0, c1 - dx);
            }
            else if(dir == 2){
                if (r1 != 0) r1 += dx;
                r2 = Math.min(n - 1, r2 + dx);
            }
            else{
                if (r2 != n - 1) r2 -= dx;
                r1 = Math.max(0, r1 - dx);
            }
            
            if (r1 >= n || r2 < 0 || c1 >= m || c2 < 0) return 0;
        }
        answer = (r2 - r1 + 1) * (c2 - c1 + 1);
        return answer;
    }
}