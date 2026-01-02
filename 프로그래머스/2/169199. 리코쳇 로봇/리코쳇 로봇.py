from collections import deque
from queue import PriorityQueue

def in_range(y, x, n, m, board):
    if 0 <= y < n and 0 <= x < m and board[y][x] != 'D':
        return True
    return False

def solution(board):
    answer = -1
    n = len(board)
    m = len(board[0])
    
    s_pos = None
    e_pos = None
    
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                s_pos = (i, j)
                break
    
    q = PriorityQueue()
    q.put((0, [s_pos[0], s_pos[1]]))
    visited = [[-1] * m for _ in range(n)]
    visited[s_pos[0]][s_pos[1]] = 0
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    
    while not q.empty():
        cnt, (y, x) = q.get()
        
        if board[y][x] == 'G':
            answer = cnt
            break
        
        for i in range(4):
            ny = y
            nx = x
            
            while in_range(ny + dy[i], nx + dx[i], n, m, board):
                ny += dy[i]
                nx += dx[i]

            if visited[ny][nx] == -1:
                visited[ny][nx] = cnt + 1
                q.put((cnt + 1, (ny, nx)))
                
    return answer