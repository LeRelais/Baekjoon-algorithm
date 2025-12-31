import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws IOException {
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   
	   String line1 = br.readLine();
	   int n = Integer.parseInt(line1), odd_cnt = 0, min_odd = 1001, sum = 0;
	   
	   StringTokenizer st = new StringTokenizer(br.readLine());
	   
	   for(int i = 0; i < n; i++){
	        int num = Integer.parseInt(st.nextToken());
	        sum += num;
	        
	        if(num % 2 == 1){
	            odd_cnt++;
	            min_odd = Math.min(min_odd, num);
	        }
	   }
	   
	   if(odd_cnt % 2 == 1){
	       sum -= min_odd;
	   }
	   
	   System.out.println(sum);
	}
}