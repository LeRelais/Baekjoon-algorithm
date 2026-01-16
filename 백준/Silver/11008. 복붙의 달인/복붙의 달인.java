import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine().trim());
	    
	        String s = st.nextToken();
	        String p = st.nextToken();
	        
	        int res = 0;
	        
	        s = s.replace(p, "#");
	        
	        for(int j = 0; j < s.length(); j++){
	            if(s.charAt(j) == '#')
	                res += 1;
	        }
	        
            String[] splits = s.split("#");
            
            
	        for(String split : splits){
	            if(!split.isEmpty()){
	                res += split.length();
	            }
	        }
	        
	        System.out.println(res);
        }
	}
}