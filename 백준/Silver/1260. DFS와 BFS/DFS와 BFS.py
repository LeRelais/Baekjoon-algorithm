# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from collections import deque

def dfs(start):
    dfsvisited[start] = True
    print(start, end=" ")

    for i in graph[start]:
        if not dfsvisited[i]:
            dfs(i)

def bfs(start):
    bfsvisited[start] = True
    q = deque([start])

    while q:
        x = q.popleft()
        print(x, end=" ")
        for i in graph[x]:
            if not bfsvisited[i]:
                bfsvisited[i] = True
                q.append(i)

n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in graph:
    i.sort()

dfsvisited = [False] * (n+1)
dfs(v)
print()
bfsvisited = [False] * (n+1)
bfs(v)
