import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   String target = br.readLine();
	   int t = Integer.parseInt(br.readLine());
	   
	   int[][] arr = new int[26][target.length()+1];
	   
	   for(int i = 0; i < 26; i++){
	       char tmp = (char)('a' + i);
	       
	       for(int j = 0; j < target.length(); j++){
	           if(target.charAt(j) == tmp){
	               arr[i][j+1] = 1 + arr[i][j];
	           }
	           else
	               arr[i][j+1] += arr[i][j];
	       }
	   }
	   
	   StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int idx = st.nextToken().charAt(0) - 'a';
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            sb.append(arr[idx][to + 1] - arr[idx][from]).append('\n');
        }
        
        // 마지막에 한 번에 출력
        System.out.print(sb);
	   
	}
}