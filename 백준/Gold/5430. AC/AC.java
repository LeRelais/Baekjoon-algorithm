import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int t = Integer.parseInt(br.readLine());
	    
	    while(true){
	        if(t <= 0)
	            break;
	        String cmd = br.readLine();
	        int n = Integer.parseInt(br.readLine());
	        String arr = br.readLine();
	        Deque<Integer> dq = new ArrayDeque<>();
	        String num = "";
	        for(int i = 1; i < arr.length()-1; i++){
	            if(arr.charAt(i) == ','){
	                dq.addLast(Integer.parseInt(num));
	                num = "";
	            }
	            else
	                num += arr.charAt(i);
	        }
	        if(!num.isEmpty())
	            dq.addLast(Integer.parseInt(num));
	            
	        boolean r_flag = false;
	        boolean e_flag = false;
	        
	        for(int i = 0; i < cmd.length(); i++){
	            if(cmd.charAt(i) == 'R'){
	                r_flag = !r_flag;
	            }
	            else{
	                if(dq.isEmpty()){
	                    e_flag = true;
	                    break;
	                }
	                if(r_flag == true){
	                    dq.pollLast();
	                }
	                else{
	                    dq.pollFirst();
	                }
	            }
	        }
	        
	        if(e_flag){
	            System.out.println("error");
	        }
	        else{
	            System.out.print("[");
	            while(!dq.isEmpty()){
	                int x;
	                if(r_flag == true){
	                    x = dq.pollLast();
	                    if(dq.isEmpty()){
	                        System.out.print(x);
	                    }
	                    else{
	                        System.out.print(x + ",");
	                    }
	                }
	                else{
	                    x = dq.pollFirst();
	                    if(dq.isEmpty()){
	                        System.out.print(x);
	                    }
	                    else{
	                        System.out.print(x + ",");
	                    }
	                }
	            }
	            System.out.println("]");
	        }
	        t--;
	    }
	}
}