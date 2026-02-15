import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {
    int[] dy = new int[]{-1, 1, 0, 0};
    int[] dx = new int[]{0, 0, -1, 1};
    int bcol, brow;
    
    public int[] solution(String[][] places) {
        int[] answer = {};
        ArrayList<Integer> res = new ArrayList<>();
        for(int t = 0; t < places.length; t++){
            String[] tmp = places[t];

            bcol = places[t].length;
            brow = places[t][0].length();
            boolean flag = true;
            
            for(int i = 0; i < tmp.length; i++){
                if(!flag)
                    break;
                for(int j = 0; j < tmp[i].length(); j++){
                    if(tmp[i].charAt(j) == 'P'){
                        if(!bfs(i, j, tmp)){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            
            if(!flag)
                res.add(0);
            else
                res.add(1);
        }
        
        answer = new int[res.size()];
        for(int i = 0; i < res.size(); i++)
            answer[i] = res.get(i);
        return answer;
    }
    
    public boolean bfs(int col, int row, String[] board){
// BFS 마다 방문 배열을 새로 만들어야 각 사람('P') 기준 탐색이 정확합니다.
    boolean[][] visited = new boolean[5][5]; 
    Queue<int[]> q = new LinkedList<>();
    
    q.add(new int[]{col, row, 0});
    visited[col][row] = true;
    
    while(!q.isEmpty()){
        int[] curr = q.poll();
        int y = curr[0];
        int x = curr[1];
        int dist = curr[2];
        
        // 거리가 2이면 더 이상 뻗어 나갈 필요 없음
        if(dist >= 2) continue;
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || visited[ny][nx]) continue;
            
            // 파티션이 있으면 통과 불가
            if(board[ny].charAt(nx) == 'X') continue;
            
            // 다른 사람을 만나면 거리두기 위반 (이미 dist < 2인 상태에서 이동했으므로)
            if(board[ny].charAt(nx) == 'P') return false;
            
            // 빈 테이블('O')이면 탐색 계속
            visited[ny][nx] = true;
            q.add(new int[]{ny, nx, dist + 1});
        }
    }
    return true;
    }
}