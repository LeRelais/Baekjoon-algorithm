import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine());
        
        int[] visited = new int[1001];
        Arrays.fill(visited, 987654321);
        
        Queue<Integer> q = new LinkedList<>();
        
        // 1. 즐겨찾기 채널 먼저 처리
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(br.readLine().trim());
            if (visited[tmp] > 1) {
                visited[tmp] = 1;
                q.add(tmp);
            }
        }
        
        // 2. 시작 채널 A 처리 (즐겨찾기보다 우선순위가 높으므로 나중에 덮어쓰거나 조건부 추가)
        if (visited[a] > 0) {
            visited[a] = 0;
            q.add(a);
        }
        
        while (!q.isEmpty()) {
            int x = q.poll();
            
            if (x == b) break; // 목표 도달 시 조기 종료 가능
            
            // +1 이동
            if (x + 1 <= 1000 && visited[x + 1] > visited[x] + 1) {
                visited[x + 1] = visited[x] + 1;
                q.add(x + 1);
            }
            
            // -1 이동
            if (x - 1 >= 0 && visited[x - 1] > visited[x] + 1) { // 범위를 0까지 허용
                visited[x - 1] = visited[x] + 1;
                q.add(x - 1);
            }
        }
        
        System.out.println(visited[b]);
    }
}