import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int n;
    static ArrayList<Integer>[] graph;
    static int[] priority, order;
    
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    n = Integer.parseInt(br.readLine());
	    
	    graph = new ArrayList[n+1];
	    
	    for(int i = 1; i <= n; i++){
	        graph[i] = new ArrayList<>();
	    }
	    
	    for(int i = 0; i < n-1; i++){
	        st = new StringTokenizer(br.readLine());
	        int a = Integer.parseInt(st.nextToken());
	        int b = Integer.parseInt(st.nextToken());
	        
	        graph[a].add(b);
	        graph[b].add(a);
	    }
	    
	    priority = new int[n+1];
	    order = new int[n+1];
	    
	    st = new StringTokenizer(br.readLine());
	   
	    for(int i = 0; i < n; i++){
	        int a = Integer.parseInt(st.nextToken());
	        priority[a] = i;
	        order[i] = a;
	    }
	    
	    if(order[0] != 1){
	        System.out.println(0);
	    }
	    else{
	        for(int i = 1; i <= n; i++){
	            Collections.sort(graph[i], (a, b) -> Integer.compare(priority[a], priority[b]));
	        }
	        
	        if(dfs(1)){
	            System.out.println(1);
	        }
	        else{
	            System.out.println(0);
	        }
	    }
	}
	
	static boolean dfs(int cur){
	    Stack<Integer> st = new Stack<>();
	    boolean[] visited = new boolean[n+1];
	    
	    List<Integer> actual = new ArrayList<>();
	    st.add(1);
	    visited[1] = true;
	    
	    while(!st.isEmpty()){
	        int x = st.pop();
	        actual.add(x);
	        
	        for(int i = graph[x].size() - 1; i >= 0; i--){
	            if(!visited[graph[x].get(i)]){
	                st.add(graph[x].get(i));
	                visited[graph[x].get(i)] = true;
	            }
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(actual.get(i) != order[i])
	            return false;
	    }
	    return true;
	}
}