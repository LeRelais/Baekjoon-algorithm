import java.io.*;
import java.util.*;
import java.lang.*;

class Solution {
    public int solution(int n, int[][] wires) {
        int answer = -1;
        int res_max = 987654321;
        ArrayList<Integer>[] arr = new ArrayList[n+1];
        for(int i = 1; i <= n; i++){
            arr[i] = new ArrayList<>();
        }
        for(int i = 0; i < wires.length; i++){
            int from = wires[i][0];
            int to = wires[i][1];
            
            arr[from].add(to);
            arr[to].add(from);
        }
        
        answer = getDiff(wires, arr, n);
        return answer;
    }
    
    public int getDiff(int[][] wires,  ArrayList<Integer>[] arr, int n){
        int res = 987654321;
        for(int i = 0; i < wires.length; i++){
            boolean[] visited = new boolean[n+1];
            int from = wires[i][0];
            int to = wires[i][1];
            
            visited[from] = true;
            visited[to] = true;
            Queue<Integer> q1 = new LinkedList<>();
            q1.add(to);
            int cnt = 0;
            int cnt1 = 1;
            while(!q1.isEmpty()){
                int x = q1.poll();
                
                for(int j = 0; j < arr[x].size(); j++){
                    int next = arr[x].get(j);
                    
                    if(visited[next] == false){
                        visited[next] = true;
                        q1.add(next);
                        cnt1+=1;
                    }
                }
            }
            cnt = n - cnt1;
            
            res = Math.min(res, Math.abs(cnt1 - cnt));
        }
        return res;
    }
}