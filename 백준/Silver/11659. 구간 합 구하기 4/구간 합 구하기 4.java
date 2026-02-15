import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] a = br.readLine().split(" ");
	    int n = Integer.parseInt(a[0]);
	    int m = Integer.parseInt(a[1]);
	    
	    String[] arr = br.readLine().split(" ");
	    int[] sum = new int[arr.length+1];
	    
	    for(int i = 1; i <= n; i++){
	        sum[i] = Integer.parseInt(arr[i-1]);
	        sum[i] += sum[i-1];
	    }
	    
	    for(int i = 0; i < m; i++){
	        String[] tmp = br.readLine().split(" ");
	        int f = Integer.parseInt(tmp[0]);
	        int b = Integer.parseInt(tmp[1]);
	        
	        System.out.println(sum[b] - sum[f-1]);
	    }
	}
}