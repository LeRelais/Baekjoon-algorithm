import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String str = br.readLine();
	    String[] splitted_strs = str.split(":");
	    
	    int n = Integer.parseInt(splitted_strs[0]);
	    int m = Integer.parseInt(splitted_strs[1]);
	    
	    int tmp = Math.min(n, m);
	    
	    int gcd = 1;
	    
	    for(int i = 2; i <= tmp; i++){
	        if(n % i == 0&& m % i == 0){
	            gcd = i;
	        }
	    }
	    
	    System.out.println(n/gcd + ":" + m/gcd);
	}
}