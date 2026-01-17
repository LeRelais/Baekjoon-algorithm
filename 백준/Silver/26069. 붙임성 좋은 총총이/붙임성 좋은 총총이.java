import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static TreeSet<String> record = new TreeSet<>();
    static int n;
    static int flag = 0;
	public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String a, b;
        n = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            a = st.nextToken();
            b = st.nextToken();
            
            if(a.equals("ChongChong") || b.equals("ChongChong")){
                flag = 1;
                record.add(a);
                record.add(b);
            }
            
            if(flag == 1){
                if(record.contains(a)){
                    record.add(b);
                }
                if(record.contains(b)){
                    record.add(a);
                }
            }
        }
        
        System.out.println(record.size());
	}
}