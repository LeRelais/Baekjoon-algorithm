import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] sizes = br.readLine().split(" ");
	    int n = Integer.parseInt(sizes[0]);
	    int m = Integer.parseInt(sizes[1]);
	    
	    int[][] arr = new int[n][m];
	    int[][] sum = new int[n+1][m+1];
	    
	    for(int i = 0; i < n; i++){
	        StringTokenizer st = new StringTokenizer(br.readLine());
	        for(int j = 0; j < m; j++){
	            arr[i][j] = Integer.parseInt(st.nextToken());
	        }
	    }
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= m; j++){
	            sum[i][j] = arr[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
	        }
	    }
	    
	    int k = Integer.parseInt(br.readLine());
	    
	    for(int i = 0; i < k; i++){
	        StringTokenizer st = new StringTokenizer(br.readLine());
	        int y1 = Integer.parseInt(st.nextToken());
	        int x1 = Integer.parseInt(st.nextToken());
	        int y2 = Integer.parseInt(st.nextToken());
	        int x2 = Integer.parseInt(st.nextToken());
	        
	        System.out.println(sum[y2][x2] - sum[y1-1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1]);
	    }
	}
}