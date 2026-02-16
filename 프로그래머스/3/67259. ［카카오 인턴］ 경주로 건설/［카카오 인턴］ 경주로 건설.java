import java.io.*;
import java.util.*;
import java.lang.*;

class DATA {
    int y, x, dir, cost;
    public DATA(int y, int x, int dir, int cost) {
        this.y = y; this.x = x; this.dir = dir; this.cost = cost;
    }
}

class Solution {
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};
    public int solution(int[][] board) {
        int n = board.length;
        // 3차원 dist 배열: [방향][y][x]
        int[][][] dist = new int[4][n][n];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) Arrays.fill(dist[i][j], Integer.MAX_VALUE);
        }

        PriorityQueue<DATA> pq = new PriorityQueue<>((a, b) -> a.cost - b.cost);

        // 시작점: 0,0에서 오른쪽(1)과 아래(2)로 출발
        // (0,0) 위치의 모든 방향에 대해 0으로 시작 가능하도록 설정
        for(int i=0; i<4; i++) {
            pq.add(new DATA(0, 0, i, 0));
            dist[i][0][0] = 0;
        }

        while (!pq.isEmpty()) {
            DATA curr = pq.poll();

            // 현재 기록된 비용보다 크면 무시 (다익스트라 최적화)
            if (dist[curr.dir][curr.y][curr.x] < curr.cost) continue;

            for (int i = 0; i < 4; i++) {
                int ny = curr.y + dy[i];
                int nx = curr.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 1) continue;

                // 비용 계산: 같은 방향이면 100원, 다른 방향이면 600원
                int nextCost = curr.cost + (curr.dir == i ? 100 : 600);

                // 3차원 배열의 해당 방향 칸에 더 저렴하게 갈 수 있다면 갱신
                if (dist[i][ny][nx] > nextCost) {
                    dist[i][ny][nx] = nextCost;
                    pq.add(new DATA(ny, nx, i, nextCost));
                }
            }
        }

        // 목적지 (n-1, n-1)에 도달한 4가지 방향 중 최솟값 찾기
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) answer = Math.min(answer, dist[i][n - 1][n - 1]);
        return answer;
    }
}