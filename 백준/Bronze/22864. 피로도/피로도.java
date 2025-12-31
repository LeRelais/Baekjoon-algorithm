import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws IOException {
	  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	  
	  StringTokenizer st = new StringTokenizer(br.readLine());
	  
	  int a = Integer.parseInt(st.nextToken());
	  int b = Integer.parseInt(st.nextToken());
	  int c = Integer.parseInt(st.nextToken());
	  int m = Integer.parseInt(st.nextToken());
	  
	  int h = 0, total_work = 0, cur_stress = 0;
	  
	  while(h < 24){
	      if(cur_stress + a <= m){
	          cur_stress += a;
	          total_work += b;
	      }
	      else{
	          cur_stress -= c;
	          if(cur_stress < 0)
	            cur_stress = 0;
	      }
	      h++;
	  }
	  
	  System.out.println(total_work);
	}
}