// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

class DATA{
    int cost;
    int from;
    int to;
    
    public DATA(int cost, int from, int to){
        this.cost = cost;
        this.from = from;
        this.to = to;
    }
}

// Please name your class Main
class Main {
    static int n;
    static ArrayList<DATA> edges = new ArrayList<>();
    static ArrayList<DATA> res = new ArrayList<>();
    static int[] parent;
	public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        n = Integer.parseInt(br.readLine());
        parent = new int[n+1];
        
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            parent[i] = i;
            for(int j = 1; j <= n; j++){
                int cost = Integer.parseInt(st.nextToken());
                
                if(j > i){
                    edges.add(new DATA(cost, i, j));
                }
            }
        }
        
        Collections.sort(edges, (a, b) -> Integer.compare(a.cost, b.cost));
        long min_cost = 0;
        for(int i = 0; i < edges.size(); i++){
            if(res.size() == n-1)
                break;
            
            DATA tmp = edges.get(i);
            int cost = tmp.cost;
            int from = tmp.from;
            int to = tmp.to;
            
            if(get_parent(from) != get_parent(to)){
                union_pts(from, to);
                res.add(tmp);
                min_cost += cost;
            }
        }
        System.out.println(min_cost);
	}
	
	public static int get_parent(int x){
	    if(x == parent[x])
	        return x;
	    return parent[x] = get_parent(parent[x]);
	}
	
	public static void union_pts(int a, int b){
	    int pa = get_parent(a);
	    int pb = get_parent(b);
	    
	    if(pa != pb){
	        if(pa > pb){
	            parent[pa] = pb;
	        }
	        else{
	            parent[pb] = pa;
	        }
	    }
	}
}