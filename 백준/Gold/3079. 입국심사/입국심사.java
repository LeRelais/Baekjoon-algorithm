import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static ArrayList<Integer> arr = new ArrayList<>();
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
	    st = new StringTokenizer(br.readLine());
	    int n = Integer.parseInt(st.nextToken());
	    int m = Integer.parseInt(st.nextToken());
	    
	    long low = 1, high = 1000000000;
	    
	    for(int i = 0; i < n; i++){
	        int tmp = Integer.parseInt(br.readLine());
	        arr.add(tmp);
	        high = Math.min(high, (long)tmp);
	    }
	    
	    Collections.sort(arr, (a, b) -> Integer.compare(a, b));
	    high *= m;
	    
	    long res = high;
	    while(low <= high){
	        long mid = (low + high) / 2;
	        
	        long cnt = 0;
	        for(int i = 0; i < arr.size(); i++){
	            cnt += mid / arr.get(i);
	            if(cnt >= m)
	                break;
	        }
	        
	        if(cnt >= m){
	            res = mid;
	            high = mid - 1;
	        }
	        else{
	            low = mid + 1;
	        }
	    }
	    
	    System.out.println(res);
	}
}