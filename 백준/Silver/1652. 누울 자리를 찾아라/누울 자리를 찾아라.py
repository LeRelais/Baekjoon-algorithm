n = int(input())
room = [input().strip() for _ in range(n)]

hori_cnt = 0
vert_cnt = 0

for i in range(n):
    for part in room[i].split('X'):
        if len(part) >= 2:
            hori_cnt += 1

for j in range(n):
    vert_str = ""
    for i in range(n):
        vert_str += room[i][j]
        
    for part in vert_str.split('X'):
        if len(part) >= 2:
            vert_cnt += 1

print(hori_cnt, vert_cnt)
            