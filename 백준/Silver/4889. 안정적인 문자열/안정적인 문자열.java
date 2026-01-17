import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static Stack<Character> st = new Stack<>();
    static int cnt = 1;
	public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        while(true){
            String str = br.readLine();
            
            if(str.charAt(0) == '-')
                break;
            
            for(int i = 0; i < str.length(); i++){
                if(st.isEmpty()){
                    st.add(str.charAt(i));
                }
                else{
                    if(str.charAt(i) == '}'){
                        if(st.peek() == '{'){
                            st.pop();
                        }
                        else{
                            st.add(str.charAt(i));
                        }
                    }
                    else
                        st.add('{');
                }
            }
            
            int res = 0;
            while(!st.isEmpty()){
                char b = st.pop();
                char a = st.pop();
                
                if(a == b){
                    res += 1;
                }
                else
                    res += 2;
            }
            
            System.out.println(cnt + ". " + res);
            cnt++;
            st.clear();
        }
        
	}
}