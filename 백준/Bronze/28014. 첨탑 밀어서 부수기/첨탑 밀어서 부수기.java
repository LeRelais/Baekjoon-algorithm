import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws IOException {
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   
	   String line1 = br.readLine();
	   int n = Integer.parseInt(line1);
	   
	   StringTokenizer st = new StringTokenizer(br.readLine());
	   
	   int prev = Integer.parseInt(st.nextToken());
	   int cnt = 1;
	   
	   for(int i = 1; i < n; i++){
            int cur = Integer.parseInt(st.nextToken());
            
            if(prev <= cur){
                cnt++;
            }
            
            prev = cur;
	   }
	   
	   System.out.println(cnt);
	}
}