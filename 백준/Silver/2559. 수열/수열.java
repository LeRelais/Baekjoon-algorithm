import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   String[] tmps = br.readLine().split(" ");
	   String[] arr = br.readLine().split(" " );
	   int[] sum = new int[arr.length+1];
	   int n = Integer.parseInt(tmps[0]);
	   int k = Integer.parseInt(tmps[1]);
	   
	   for(int i = 1; i <= n; i++){
	       sum[i] = Integer.parseInt(arr[i-1]);
	       sum[i] += sum[i-1];
	   }
	   
	   int res = Integer.MIN_VALUE;
	   
	   for(int i = k; i <= n; i++){
	       res = Math.max(res, sum[i] - sum[i-k]);
	   }
	   System.out.print(res);
	}
}