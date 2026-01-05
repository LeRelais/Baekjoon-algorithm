import sys

attendance = {}

s, e, q = input().strip().split(' ')

records = sys.stdin.read().splitlines()

for record in records:
    t, name = record.split(' ')
    
    if t <= q:
        attendance.setdefault(name, []).append(t)

keys = attendance.keys()

res = 0

for key in keys:
    attendance[key].sort()
    #print(key, attendance[key])
    if len(attendance[key]) >= 2:
        if attendance[key][0] <= s and e <= attendance[key][len(attendance[key]) - 1] <= q:
            res += 1  

print(res)