from collections import deque

def solution(x, y, n):
    answer = -1
    
    q = deque([x])
    visited = [-1] * (y+1)
    visited[x] = 0
    
    while q:
        num = q.popleft()
        
        if num == y:
            answer = visited[num]
            break
        
        if num * 2 <= y and visited[num*2] == -1:
            visited[num*2] = visited[num] + 1
            q.append(num*2)
        if num * 3 <= y and visited[num*3] == -1:
            visited[num*3] = visited[num] + 1
            q.append(num*3)
        if num + n <= y and visited[num + n] == -1:
            visited[num + n] = visited[num] + 1
            q.append(num + n)
    
    return answer