import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static boolean[] used = new boolean[10];
	public static TreeSet<String> results = new TreeSet<>();
	
	static void make_num(int nth, String str, int n, String[] signs){
	    if(nth == n+1){
	        results.add(str);
	        return;
	    }
	    
	    for(int i = 0; i < 10; i++){
	        if(signs[nth-1].equals("<")){
	            if(str.charAt(nth-1) - '0' < i && !used[i]){
	                used[i] = true;
	                make_num(nth+1, str + i, n, signs);
	                used[i] = false;
	            }
	        }
	        
	        if(signs[nth-1].equals(">")){
	            if(str.charAt(nth-1) - '0' > i && !used[i]){
	                used[i] = true;
	                make_num(nth+1, str + i, n, signs);
	                used[i] = false;
	            }	            
	        }
	    }
	    
	}
	
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int n = Integer.parseInt(br.readLine().trim());
	    String[] signs = br.readLine().split(" ");
	    
	    for(int i = 0; i < 10; i++){
	       used[i] = true;
	       make_num(1, String.valueOf(i), n, signs);
	       used[i] = false;
	    }
	    
	    System.out.println(results.last() + "\n" + results.first());
	}
}